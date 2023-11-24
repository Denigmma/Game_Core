#pragma once

class Down : public Cell {
public:
	void performAction(Player& player) override {
		actionlogic(player, -1);
	}
	void printDescription() const override {
		std::cout << "Шаг назад на 1 клетку." << std::endl;
	}
};