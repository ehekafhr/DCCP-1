#include "Printer.h"

void Printer::print(int octave, Sheet& sheet) {
	
	// Ÿ��Ʋ
	std::cout << "DCCP: DGIST Convergence Composer Program" << std::endl;

	std::cout << std::endl;

	// ���� ��� ��1
	std::cout << std::setw(11) << std::left << "BPM: " << sheet.BPM << ", ";
	std::cout << std::setw(16) << std::left << "Current Octave: " << std::setw(2) << std::left  << octave;
	for (int i = 0; i < 90; ++i) {
		std::cout << '-';
	}

	std::cout << std::endl;
	std::cout << std::endl;

	// Cursor Ŀ�� ��1
	std::cout << std::setw(8) << std::left << "Cursor";
	int pos = sheet.cursor.getPosition();
	for (int i = 0; i < 24; ++i) {
		if (i == pos) {
			std::cout << "V   ";
		}
		else {
			std::cout << "    ";
		}
	}

	std::cout << std::endl;
	std::cout << std::endl;


	// Order ���� ��1
	std::cout << std::setw(8) << std::left << "Order";
	for (int i = 0; i < 24; ++i) {
		std::cout << std::setw(4) << std::left << i;
	}	

	std::cout << std::endl;
	std::cout << std::endl;

	// Pitch ���̸� ��1
	std::cout << std::setw(8) << std::left << "Pitch";
	for (int i = 0; i < 24; ++i) {
		std::cout << std::setw(4) << std::left << sheet.getNote().getPitch();
	}

	std::cout << std::endl;
	std::cout << std::endl;

	// length ���� ��1
	std::cout << std::setw(8) << std::left << "Rhythm";
	for (int i = 0; i < 24; ++i) {
		std::cout << std::setw(4) << std::left << sheet.getNote().getRhythm();
	}

	std::cout << std::endl;
	std::cout << std::endl;

	// �Ʒ��� ��� ��1
	for (int i = 0; i < 119; ++i) {
		std::cout << '-';
	}

	std::cout << std::endl;
	std::cout << std::endl;

	
	// ���� ��� ��2
	for (int i = 0; i < 119; ++i) {
		std::cout << '-';
	}

	std::cout << std::endl;
	std::cout << std::endl;

	// Cursor Ŀ�� ��2
	std::cout << std::setw(8) << std::left << "Cursor";
	for (int i = 24; i < 48; ++i) {
		if (i == sheet.cursor.getPosition()) {
			std::cout << "V   ";
		}
		else {
			std::cout << "    ";
		}
	}

	std::cout << std::endl;
	std::cout << std::endl;


	// Order ���� ��2
	std::cout << std::setw(8) << std::left << "Order";
	for (int i = 24; i < 48; ++i) {
		std::cout << std::setw(4) << std::left << i;
	}	

	std::cout << std::endl;
	std::cout << std::endl;

	// Pitch ���̸� ��2
	std::cout << std::setw(8) << std::left << "Pitch";
	for (int i = 24; i < 48; ++i) {
		std::cout << std::setw(4) << std::left << sheet.getNote().getPitch();
	}

	std::cout << std::endl;
	std::cout << std::endl;

	// length ���� ��2
	std::cout << std::setw(8) << std::left << "Rhythm";
	for (int i = 24; i < 48; ++i) {
		std::cout << std::setw(4) << std::left << sheet.getNote().getRhythm();
	}

	std::cout << std::endl;
	std::cout << std::endl;

	// �Ʒ��� ��� ��2
	for (int i = 0; i < 53; ++i) {
		std::cout << '-';
	}
	std::cout << std::setw(7) << std::left << " page: " << std::setw(5) << std::left << sheet.page.getPosition();
	for (int i = 0; i < 54; ++i) {
		std::cout << '-';
	}

	std::cout << std::endl;
}

// x is the column, y is the row. The origin (0,0) is top-left.
void Printer::setCursorPosition(int x, int y) {
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}