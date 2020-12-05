#pragma once
#include <windows.h>

class Note{
public:
	// 1, 0�� �ʱ�ȭ���� ���� NULL_NOTE�� ����
	// ��ǥ�� 0, length
	Note() {
		freq = 0;
		length = 0;
		is_NULL = true;
		is_rest = false;
	}
	Note(int, char, char);
	Note(int, int);

	bool is_NULL;
	bool is_rest;
	int freq;
	int length;
	void beep();

	const char* getPitch();
	const char* getLength();

private:
	// ���� ������ ��Ȯ���� ���� double�� ���. ���� ���� ������ ��ȯ�� ������ �Ҽ��� ���ϴ� ����.
	double pitchToFreq(char);
	int rhythmToLength(char);

	// ���̸��� �����ϱ� ���ؼ� �����ϴ� 
	int oct = 0;
	char pit[4] = { '\0' , '\0' , '\0' , '\0' };
};

