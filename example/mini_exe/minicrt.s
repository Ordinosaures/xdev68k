*
* ���s�t�@�C���̃G���g���|�C���g�ɂȂ�R�[�h
*
* ���̃t�@�C�������s�t�@�C���̃G���g���|�C���g�ɂ���ɂ́A���̃t�@�C������
* ���������I�u�W�F�N�g�t�@�C�����A�����N���X�g�̐擪�Ɏw�肷��K�v������B
*

	.cpu 68000
	.include doscall.inc
	.include iocscall.inc

	.text
	.even

	move.l	a4, -(sp)		* �v���O�����̎��s�J�n�A�h���X
	move.l	a3, -(sp)		* ���̃A�h���X
	move.l	a2, -(sp)		* �R�}���h���C���̃A�h���X
	move.l	a1, -(sp)		* �v���O�����̏I���+1 �̃A�h���X
	move.l	a0, -(sp)		* �������Ǘ��|�C���^�̃A�h���X
	jbsr	_asmMain		* �A�v���P�[�V���� main ���Ăяo��
	add.l	#4*5,sp

	move.w	d0,-(sp)
	dc.w	__EXIT2

