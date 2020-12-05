#pragma once
#include "Note.h"

#include <vector>

#include "cursor.h"
#include "page.h"

class Paper {
private:
	// �� �������� �ִ� note ���� 48�� ������ �����Ѵ�.
	Note note_array[48];
	int size = 0;
public:
	Paper();

	bool isFull() { return size == 48; }
	bool isEmpty() { return size == 0; }
	bool getSize() { return size; }

	void insert(int, Note);
	void remove(int);
	void replace(int, Note);
	Note getNote(int idx) {
		return note_array[idx];
	}
};

class Sheet{
private:
	// Paper��ü�� Note�� ���, Sheet�� Paper�� ��´�.
	// �ִ� ������ ���� 30�̰�,
	// �� �������� �ִ� note ���� 48�� ������ �����Ѵ�.
	Paper paper_array[30];	// ����ִ� �����۰� ���� �� ���·� �ʱ�ȭ�ȴ�.

public:
	Sheet();

	// Ŀ���� ������ ��ü
	Cursor cursor;
	Page page;


	// -------- ������ --------
	// ���� Ŀ���� ������ ��ġ�� �־��� ���̸��� ������ ��Ʈ�� ���� �����Ѵ�.
	Note insert(const char*, const char*);		// ��Ʈ�� �Ǻ��� ������ �� ���� �Ҹ��� �����Ѵ�.
	// ���� Ŀ���� �������� �ִ� ��Ʈ�� �����Ѵ�.
	void remove(int number = 1);
	// ���� Ŀ���� �������� �ִ� ��Ʈ�� �־��� ���̸��� ������ ��Ʈ�� �����Ѵ�.
	Note replace(const char*, const char*);

	// ���� Ŀ���� ������ ��ġ�� �ִ� ��Ʈ�� �����Ѵ�.
	Note getNote() {
		return paper_array[page.getPosition()].getNote(cursor.getPosition());
	}

	// �������� ���� ������� �˷��ִ� ����
	int eop = 0;	// End Of Page
	// �߰� ������ �ʿ��ϴ�.

	void update_eop() {
		int count = 0;
		// ���ǰ� �ִ� Paper�� ���� ��ŭ i�� ������Ų��.
		while (paper_array[count].isEmpty() != true) {
			++count;
		}

		// eop�� ���ǰ� �ִ� Paper�� ������ �ƴ϶�, ������ page�� ���� ��Ÿ���� �����̹Ƿ� 1�� ����.
		eop = count - 1;
	}

	int BPM = 200;
};

