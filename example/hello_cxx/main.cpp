/*
	C++ �𗘗p�����ł���{�I�ȃT���v���R�[�h�ł��B

	[���]
		�N���X���`���A�R���X�g���N�^�A�f�X�g���N�^�A����у��[�U�[��`
		���\�b�h����A�R���\�[���� printf �ŕ�������o�͂��܂��B

	[!!!!! ���� !!!!!]
		���� xdev68k ��ł� C++ ���p�͐��񂪂ƂĂ������ł��B

		1) C++ �W���w�b�_�̑����� include �Ɏ��s����
			C++ �W���w�b�_�̑����� include �������_�ŃR���p�C���G���[��
			�Ȃ�܂��B���̖�����������ɂ́Aglibc �����̊��� xdev68k
			�ɈڐA����K�v������܂����A������ƂȂ��Ă��܂��B
			���̂��� std::cout �͗��p�ł����A���̃T���v���R�[�h�ł͑��
			��i�Ƃ��� printf �𗘗p���Ă��܂��B

		2) ��O�� RTTI �������Ȃ�
			��O�� RTTI �𗘗p����ƁA���T�|�[�g�� GAS �f�B���N�e�B�u���o��
			����邽�߁A�A�Z���u���Ɏ��s���܂��B��O����� RTTI �𖳌���
			����ɂ́Am68k-elf-g++ �̃R���p�C���I�v�V������
				-fno-rtti -fno-exceptions
			���w�肷��K�v������܂��B�ڂ����� makefile ���Q�Ƃ��Ă��������B
*/

/*
	XC �̃w�b�_�� c++ ��z�肵�Ă��Ȃ��̂� extern "C" �̓A�v���P�[�V��������
	�s���K�v������܂��B
*/
#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>

#ifdef __cplusplus
}
#endif


class Example {
public:
	void hello() {
		printf("hello c++ world.\n");
	}
	Example() {
		printf("ctor.\n");
	}
	~Example() {
		printf("dtor.\n");
	}
};


int main(int argc, char *argv[]){
	Example example;
	example.hello();
	return 0;
}

