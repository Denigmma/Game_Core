#pragma once
class Next : public Cell {
public:
	void performAction(Player& player) override {
		actionlogic(player, 1);
	}

	void printDescription() const override {
		std::cout << "��� ������ �� 1 ������." << std::endl;
	}
};