/*
	�X�[�p�[�o�C�U���[�h�ƃ��[�U�[���[�h�̐؂�ւ����s���܂��B

	[���]
		X680x0 �̃v���O�����R�[�h����n�[�h�E�F�A���W�X�^�Ȃǂɒ��ڃA�N�Z�X
		���鎞�́A�X�[�p�[�o�C�U�ƌĂ΂��������[�h�ɓ���K�v������܂��B

		�v���O�����N�����̓��[�U�[���[�h�ɂȂ��Ă���AIOCS �R�[���� B_SUPER
		�����s���邱�ƂŃX�[�p�[�o�C�U���[�h�ɓ��邱�Ƃ��ł��܂��B
		�]���A���̂悤�ȏ����́AIOCSLIB.L �Ɋ܂܂�� B_SUPER() �֐���p����
		���̂悤�ɋL�q���邱�Ƃ��\�ł����B

			// �X�[�p�[�o�C�U���[�h�ɓ���i���F�댯�ȃR�[�h�ł��j
			int usp = B_SUPER(0);

			�i�n�[�h�E�F�A�Ȃǂɒ��ڃA�N�Z�X���鏈���j

			// ���[�U�[���[�h�ɕ��A����i���F�댯�ȃR�[�h�ł��j
			if (usp > 0) {
				B_SUPER(usp);
			}

		���������݂� gcc ���ł́A�X�^�b�N�ꊇ�␳�Ȃǂ̍œK�����ϋɓI��
		�s����s���A��L�̂悤�ȋL�q�͊댯�ł��B

		���̖��̉����@�� 3 �ʂ�l�����܂��B

		1) �R���p�C���̍œK���𖳌��ɂ���
			gcc �� pragma �𗘗p���邱�ƂŁA�Ǐ��I�ɍœK���𖳌������邱�Ƃ�
			�\�ł��B

		2) �A�Z���u���𗘗p����
			�X�[�p�[�o�C�U���[�h�ɓ����Ă����Ԃ̃R�[�h�́A�R���p�C����
			�œK�����������̂�����邽�߁A���ׂăA�Z���u���ŋL�q���܂��B

		3) �v���O�����J�n�ƂƂ��ɃX�[�p�[�o�C�U���[�h�ɓ��蕜�A���Ȃ�
			�X�[�p�[�o�C�U���[�h����̕��A���l��������΁A�����������̖���
			�l������K�v�͂���܂���B

		�����ł́A(1) �̕��@�𗘗p���܂��B
*/

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <iocslib.h>
#include <doslib.h>


/* GCC �̃R���p�C���I�v�V������ޔ� */
#pragma GCC push_options

/* GCC �̃X�^�b�N�ꊇ�␳�𖳌����i���̌�� pragma GCC pop_options �ōĂїL���������j*/
#pragma GCC optimize("-fno-defer-pop")

/* �������v�̏�Ԃ��擾 */
uint32_t getRtc(){
	/* �X�[�p�[�o�C�U���[�h�Ɉڍs���� */
	intptr_t usp = B_SUPER(0);

	/* �n�[�h�E�F�A�ɒ��ڃA�N�Z�X���������v�̏�Ԃ��擾�i�X�[�p�[�o�C�U���[�h�łȂ��ƃG���[�ɂȂ�j*/
	uint32_t rtc = *(uint32_t *)0xE8A000;

	/* ���[�U�[���[�h�ɕ��A���� */
	if (usp > 0) {
		B_SUPER(usp);
	}

	return rtc;
}

/* GCC �̃R���p�C���I�v�V�����𕜊� */
#pragma GCC pop_options


int main(int argc, char *argv[]){
	/* �����L�[���������܂ŌJ��Ԃ� */
	while (INPOUT(0xFF) == 0) {
		printf("RTC = %08X\n", getRtc());
	}

	return 0;
}

