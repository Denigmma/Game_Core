#pragma once
class Zero : public Cell {
public:
	void performAction(Player& player) override {
		actionlogic(player, 0);
	}

	void printDescription() const override {
		std::cout << "������ ����� �� �����. ��� ������ � 0." << std::endl;
	}
};