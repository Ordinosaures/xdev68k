/*
	main �֐��𗘗p���Ȃ����ƂŁA�����Ȏ��s�t�@�C�����쐬���܂��B

	[���]
		C/C++�Ŏ��s�t�@�C�����쐬����ƁAmain �֐�����A�v���P�[�V�������J�n
		���邽�߃����^�C�����C�u�����������N����Ă��܂��A�t�@�C���T�C�Y��
		��債�܂��B

		���̖����������ɂ́Amain �֐��𗘗p�����A���O�ŗp�ӂ����G���g��
		�|�C���g����v���O�������J�n����悤�Ȏ������쐬����K�v������܂��B
		�����Ă��̂悤�ȃA�v���P�[�V�����ł́AC�W���֐������p�s�\�ɂȂ�̂ŁA
		�l�X�ȏ��������O�Ŏ�������K�v�������܂��B

		main �֐��𗘗p���Ȃ��ꍇ�A�����̎�Ԃ͑����Ă��܂��܂����A�t�@�C��
		�T�C�Y���L���o�C�g�̏����Ȏ��s�t�@�C�����쐬���邱�Ƃ��ł��܂��B
		�t���b�s�[�f�B�X�N�̂悤�ȁA�e�ʐ����̌��������f�B�A�Ɏ��^������s
		�t�@�C�����쐬����ꍇ�ɁA���̎�@�͗L���ȗe�ʍ팸��i�ƂȂ�܂��B

		�{�T���v���R�[�h�̋N���͈ȉ��̏����ōs���܂��B

			1) minicrt.s ����v���O�����̎��s���J�n����B
			2) minicrt.s ���� asmMain() �֐������s����B
			3) asmMain() �֐��ŁA�R�}���h���C����������͂���B
			4) �R�}���h���C����������͌��ʂ�^���� appMain() �֐������s����B
*/

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "dos_call.h"
#include "app.h"


int appMain(int argc, char *argv[]) {
	/* ������ TTY �o�� */
	for (int i=0; i<argc; i++) {
		dosPrint(argv[i]);
		dosPrint("\r\n");
	}

	return EXIT_SUCCESS;
}

