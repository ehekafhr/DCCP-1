#include "Sheet.h"


Sheet::Sheet() {
	for (int i = 0; i < 30; ++i) {
		Paper new_paper;
		paper_array[i] = new_paper;
	}
}

void Sheet::insert(Cursor& cursor, Page& page, Note note) {
	paper_array[page.getPosition()].insert(cursor.getPosition(), note);
}

void Sheet::remove(Cursor& cursor, Page& page, int number) {
	for (int i = 0; i < number; ++i) {
		paper_array[page.getPosition()].remove(cursor.getPosition());
	}
}

void Sheet::replace(Cursor& cursor, Page& page, Note note) {
	paper_array[page.getPosition()].insert(cursor.getPosition(), note);
}



Paper::Paper() {
	for (int i = 0; i < 48; ++i) {
		Note new_note;
		note_array[i] = new_note;
	}
}

void Paper::insert(int idx, Note note) {
	// ���� ������ ��������� �ƹ��͵� ���� �ʴ´�. �ٸ��� ����� �ض�.
	if (isFull() == true) {
		//do nothing
	}
	else {
		// �ش� �ε����� �ٸ� ��Ʈ�� �ִ��� �˻��Ѵ�. (�γ�Ʈ�� ��������� ����ִٴ� ��)
		if (note_array[idx].is_NULL== true) {
			note_array[idx] = note;	// ���� ���ٸ� �׳� �����Ѵ�.
		}
		// ���� �ش� �ε����� ���ڰ� �ִٸ� �� ĭ�� �ڷ� �̷�� �ִ´�.
		else {
			for (int i = 47; i >= idx; --i) {
				note_array[i] = note_array[i - 1];
			}
			note_array[idx] = note;
		}

		++size;	//������ ����
	}
}

void Paper::remove(int idx) {
	// ���� null��Ʈ ���� �ε������ �ƹ� �͵� ���� �ʴ´�.
	if (note_array[idx].is_NULL == true) {
		// do nothing
	}
	// �׷��� �ʰ� ���� ���� �ִٸ�
	else {
		// �� null��Ʈ�� �־ ���� ó���Ѵ�.
		note_array[idx] = Note();

		--size;	// ������ ����
	}
}

void Paper::replace(int idx, Note note) {
	note_array[idx] = note;
}