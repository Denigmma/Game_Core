#pragma once
bool flag_health = false;
class Died : public Cell {
public:
	void performAction(Player& player) override {
		if (flag_health == false) {
			actionlogic(player, -(SizeBoard::COLS * SizeBoard::ROWS));
			p = true;
		}
		else {
			p = false;
			flag_health = false; // ++ �������� ��������� ������ ++
		}
	}

	void printDescription() const override {
		if (p == true) {
			std::cout << "�� ���������! �������� �������." << std::endl;
		}
		else {
			std::cout << "��� ������ ������ �� ������! ���������� ����" << std::endl;
		}
		bool p=NULL;
	}
private:
	bool p;
};