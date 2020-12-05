#pragma once
#include <windows.h>

class Note{
public:
	// NULL_Note�� ���ļ��� �������, ���̰� 0�̴�.
	// ��ǥ�� ���ļ��� 0�̰� ���̸� ���´�.
	Note() {
		freq = 0;
		length = 0;
		is_NULL = true;
		is_rest = true;
	}
	Note(int, char, char);

	Note(const char*, const char*);

	Note(int, int);
	// ������ ������ ��ο��� ��� ��� ������ �ʱ�ȭ�ȴ�.

	bool is_NULL;
	bool is_rest;

	char* pitch;
	char* rhythm;

	int freq;		// ��Ʈ�� �ش��ϴ� ���� ���ļ��� ������ ����.
	int length;		// ��Ʈ�� �ش��ϴ� ���� ���̸� ������ ����.
	const char* getPitch();		// ��Ʈ�� ���̸��� �����Ѵ�. private ������ pit (char�迭)�� ���� �������ش�.
	const char* getLength();	// ��Ʈ�� ���� ���̸� ���ڷ� ��ȯ�Ͽ� �����Ѵ�. ex) 1200 / lengthPerBit -> "1/1".
	
	void beep();

	int lengthPerBit = 150;		// Bpm�� 200���� �����Ѵ�.

private:
	// ���� ������ ��Ȯ���� ���� double�� ���. ���� ���� ������ ��ȯ�� ������ �Ҽ��� ���ϴ� ����.
	double pitchToFreq(char);
	int rhythmToLength(char);

	// ���̸��� �����ϱ� ���ؼ� �����ϴ� 
	int oct = 0;
	char pit[4] = { '\0' , '\0' , '\0' , '\0' };

	// ��Ʈ�� ��밡�� �� ��������(������ ���� ��������) �˻��Ѵ�.
	// ������ �ִٸ� throw
	void validate();
};

