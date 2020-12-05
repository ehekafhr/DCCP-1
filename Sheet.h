#pragma once
#include "Note.h"
#include "Cursor.h"
#include "Page.h"
#include <vector>

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
	// ������
	void insert(Cursor&, Page&, Note);
	void remove(Cursor&, Page&, int number = 1);
	void replace(Cursor&, Page&, Note);
	Note getNote(int pos, Page& page) {
		return paper_array[page.getPosition()].getNote(pos);
	}
};


