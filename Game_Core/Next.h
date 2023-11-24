#pragma once
class Next : public Cell {
public:
	void performAction(Player& player) override {
		actionlogic(player, 1);
	}

	void printDescription() const override {
		std::cout << "Шаг вперед на 1 клетку." << std::endl;
	}
};