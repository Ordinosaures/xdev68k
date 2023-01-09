/*
	�q�[�v�T�C�Y���g������菇�������܂��B

	[���]
		�A�v���P�[�V�����N�����_�ł͏��Ȃ��q�[�v�������������p�ł��܂���B

		stdlib.h �Ő錾����Ă��� allmem() �֐������s����ƁA�q�[�v�T�C�Y��
		�ő剻����A�傫�ȃ������u���b�N���m�ۉ\�ɂȂ�܂��B

		�{�T���v���R�[�h�����s����ƁA��Ƃ��� 12MB ���ł͈ȉ��̂悤�ɏo��
		����܂��B�q�[�v�T�C�Y���ő剻����Ă��邱�Ƃ��m�F�ł��܂��B

			before allmem()
			heap free size = 65280 bytes
			after allmem()
			heap free size = 12073728 bytes
*/
#include <stdlib.h>
#include <stdio.h>


/* �m�ۉ\�ȃq�[�v�e�ʂ̍ő�l���i�͋Z�Łj���߂܂� */
size_t get_heap_free_size() {
	size_t size;
	size_t step = 256;
	for (size = step; size < 1024 * 1024 * 1024; size += step) {
		void *p = malloc(size);
		if (p == NULL) {
			return size - step;
		}
		free(p);
	}
	return size;
}

int main(int argc, char *argv[]){
	/* �g���O�̃q�[�v�T�C�Y�����߂� */
	printf("before allmem()\n");
	printf("heap free size = %d bytes\n", (int)get_heap_free_size());

	/* �q�[�v�T�C�Y���g�� */
	allmem();

	/* �g����̃q�[�v�T�C�Y�����߂� */
	printf("after allmem()\n");
	printf("heap free size = %d bytes\n", (int)get_heap_free_size());
}


