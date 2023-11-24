#pragma once
class Zero : public Cell {
public:
	void performAction(Player& player) override {
		actionlogic(player, 0);
	}

	void printDescription() const override {
		std::cout << "Просто стоим на месте. Шаг длиной в 0." << std::endl;
	}
};