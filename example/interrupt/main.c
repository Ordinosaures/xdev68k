/*
	���荞�ݏ����� C �֐��ŋL�q���܂��B

	[���]
		���荞�݊֐��� C �֐��ŋL�q����ꍇ�́A�֐��錾����
			__attribute__((interrupt))
		���w�肵�܂��B

		���̂悤�ɐ錾���ꂽ�֐��́A�S���W�X�^��ۑ����A�֐��� rte ���߂ŏI��
		����悤�ȓ���ɂȂ�܂��B

	[!!!!! ���� !!!!!]
		�Â� X68000 gcc ���iver1.42�A2.95 �Ȃǁj�ł́A�֐��I������ IRTE() ��
		�悤�ȃ}�N�������s���܂������A���̕K�v�͂Ȃ��Ȃ�܂����B
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <doslib.h>
#include "func.h"


/* �����A�����Ԋ��荞�݉񐔂��J�E���g����ϐ� */
volatile int g_count = 0;


/* �����A�����Ԋ��荞�݂Ŏ��s�����֐� */
void __attribute__((interrupt)) vsyncInterrupt(void) {
	g_count++;
}


int main(int argc, char *argv[]){
	/* �����A�����Ԋ��荞�݊J�n */
	initVsyncInterrupt(vsyncInterrupt);

	/* ���݂̃J�E���^�l���擾 */
	int current = g_count;

	/* �����L�[���������܂ŌJ��Ԃ� */
	while (INPOUT(0xFF) == 0) {
		printf("vsync count = %d\n", current);

		/* �����A�����Ԋ��荞�݂ɂ�� g_count ���X�V�����̂�҂� */
		while (current == g_count) {}

		/* ���݂̃J�E���^�l���擾���Ȃ��� */
		current = g_count;
	}

	/* �����A�����Ԋ��荞�ݒ�~ */
	termVsyncInterrupt();

	return 0;
}

