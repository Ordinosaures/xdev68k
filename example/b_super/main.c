/*
	スーパーバイザモードとユーザーモードの切り替えを行います。

	[解説]
		X680x0 のプログラムコードからハードウェアレジスタなどに直接アクセス
		する時は、スーパーバイザと呼ばれる特権モードに入る必要があります。

		プログラム起動時はユーザーモードになっており、IOCS コールの B_SUPER
		を実行することでスーパーバイザモードに入ることができます。
		従来、このような処理は、IOCSLIB.L に含まれる B_SUPER() 関数を用いて
		次のように記述することが可能でした。

			// スーパーバイザモードに入る（注：危険なコードです）
			int usp = B_SUPER(0);

			（ハードウェアなどに直接アクセスする処理）

			// ユーザーモードに復帰する（注：危険なコードです）
			if (usp > 0) {
				B_SUPER(usp);
			}

		しかし現在の gcc 環境では、スタック一括補正などの最適化が積極的に
		行われる都合、上記のような記述は危険です。

		この問題の回避方法は 3 通り考えられます。

		1) コンパイラの最適化を無効にする
			gcc の pragma を利用することで、局所的に最適化を無効化することが
			可能です。

		2) アセンブラを利用する
			スーパーバイザモードに入っている区間のコードは、コンパイラの
			最適化が介入するのを避けるため、すべてアセンブラで記述します。

		3) プログラム開始とともにスーパーバイザモードに入り復帰しない
			スーパーバイザモードからの復帰を考え無ければ、そもそもこの問題を
			考慮する必要はありません。

		ここでは、(1) の方法を利用します。
*/

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <iocslib.h>
#include <doslib.h>


/* GCC のコンパイルオプションを退避 */
#pragma GCC push_options

/* GCC のスタック一括補正を無効化（この後の pragma GCC pop_options で再び有効化される）*/
#pragma GCC optimize("-fno-defer-pop")

/* 内部時計の状態を取得（上位16bit=秒の1桁目、下位16bit=秒の2桁目）*/
uint32_t getRtc(){
	/* スーパーバイザモードに移行する */
	intptr_t usp = B_SUPER(0);

	/* ハードウェアに直接アクセスし内部時計の状態を取得する（スーパーバイザモードでないとエラーになる）*/
	uint32_t rtc;
	do {
		/*
			RTC の複数のレジスタをアトミックに読むことはできないので、
			秒の1桁目と2桁目をズレなく同時に取得するには工夫が必要。
			ここでは、同じ値が 2 回読めるまで do〜while で繰り返す方法を利用している。
		*/
		rtc = *(volatile uint32_t *)0xE8A000 & 0x000F0007;
	} while (rtc != (*(volatile uint32_t *)0xE8A000 & 0x000F0007));

	/* ユーザーモードに復帰する */
	if (usp > 0) {
		B_SUPER(usp);
	}

	return rtc;
}

/* GCC のコンパイルオプションを復活 */
#pragma GCC pop_options


int main(int argc, char *argv[]){
	/* 何かキーが押されるまで繰り返す */
	while (INPOUT(0xFF) == 0) {
		printf("RTC = %08X\n", getRtc());
	}

	return 0;
}

