#pragma once
class Drop : public Cell {
public:
	void performAction(Player& player) override {
		actionlogic(player, -3);
	}
	void printDescription() const override {
		std::cout << "Шаг назад на 3 клетки." << std::endl;
	}
};