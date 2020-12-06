#pragma once
#include "Sheet.h"
#include <iostream>
#include <iomanip>


class Printer{
public:
	void print(int octave, int mode, Sheet&);
    // 0 ���� ���
    // 1 ��ü ���
    // 2 ���� ���

    // x is the column, y is the row. The origin (0,0) is top-left.
    void setCursorPosition(int x, int y);

    // x, y��ǥ�� txt�� ����Ѵ�.
    void printAt(const char* txt, int x, int y);
};

