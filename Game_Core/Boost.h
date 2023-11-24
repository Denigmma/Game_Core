#pragma once
class Boost : public Cell {
public:
	void performAction(Player& player) override {
		actionlogic(player, 3);
	}

	void printDescription() const override {
		std::cout << "Ускоренный шаг вперед на 3 клетки." << std::endl;
	}
};