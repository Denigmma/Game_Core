#pragma once
#include "SizeBoard.h"

class Trigonom : public Cell {
public:
	void performAction(Player& player) override {
		std::cout << "�������� ���������� �����:" << std::endl;
		std::cout << "1=..." << std::endl;
		std::cout << "1) cos(x+y)+sin(x-y)" << std::endl;
		std::cout << "2) ctg(x)+sin(x) " << std::endl;
		std::cout << "3) sin^2(x)+cos^2(x) " << std::endl;
		std::cout << "4) tg(x)*ctg(x)" << std::endl;

		int contans, conttrue1 = 3, conttrue2 = 4;
		std::cin >> contans;

		if ((conttrue1 == contans) || (conttrue2 == contans)) {
			flag = true;
			actionlogic(player, 2);
		}
		else {
			flag = false;
			actionlogic(player, -1);
		}
	}
	void printDescription() const override {
		if (flag == true) {
			std::cout << "������� �� ������� �� �������? �� ������������ �� 2 ������ ������" << std::endl;
		}
		else {
			std::cout << "������ ����� �� �����... �� ������������ �� 1 ������ �����" << std::endl;
		}
	}
};