#pragma once

class Geometry : public Cell {
public:
	void performAction(Player& player) override {
		std::cout << "� ��� ������ ������� ��������? " << std::endl;
		std::cout << "1) ��� ������ ���������� ���������������� ������������ ��� ����������\n ����� ����� ������������ ������ ���� ��������������� ������" << std::endl;
		std::cout << "2) � ����� ������������ ����� ���������� ����� ����� 180`" << std::endl;
		std::cout << "3) ���� ����� ����������� � ������, ����������� ����� ����� �������,\n ����� �������� ������� �������� ����, ����������� ����� ����." << std::endl;
		std::cout << "4) ���� ��� ������������ ������ ���������� �������, �� ��������������� ���� �����." << std::endl;

		int contans, conttrue1 = 1;
		std::cin >> contans;

		if (conttrue1 == contans) {
			flagGeometry = true;
			actionlogic(player, 2);
		}
		else {
			flagGeometry = false;
			actionlogic(player, -2);
		}
	}
	void printDescription() const override {
		if (flagGeometry == true) {
			std::cout << "������� �� ������� �� �������? �������� �������� ����!\n �� ������������ �� 2 ������ ������" << std::endl;
		}
		else {
			std::cout << "������ ����� �� �����... ������ ������ � ��� ���� ����� ���!\n �� ������������ �� 1 ������ �����" << std::endl;
		}
	}
private:
	bool flagGeometry;
};