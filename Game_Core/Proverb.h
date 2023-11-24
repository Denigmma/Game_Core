#pragma once
#include "SizeBoard.h"
#include "Cell.h"

class Proverb : public Cell {
public:
	void performAction(Player& player) override {
		std::cout << "���������� �����, ������ ���������� �����:" << std::endl;
		//std::cout << "��� - ����, ��� ��������. ����������� ���� ... " << std::endl;
		std::cout << "�� ����� ����� � ��������, ������ � � ��� ..." << std::endl;
		std::cout << "1) ����� ����� ����" << std::endl; \
			std::cout << "2) ������� ���� ���" << std::endl;
		std::cout << "3) ����� ���� ����" << std::endl;
		std::cout << "4) ���� ������" << std::endl;

		int contans, conttrue = 3;
		std::cin >> contans;

		if (contans == conttrue) {
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
			std::cout << "�� �� ������! �� ������������ �� 2 ������ ������" << std::endl;
		}
		else {
			std::cout << "������ ����� �� �����... �� ������������ �� 1 ������ �����" << std::endl;
		}

	}
};