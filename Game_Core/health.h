#pragma once
class health : public Cell {
public:
	void performAction(Player& player) override {
		flag_health = true;
	}

	void printDescription() const override {
		std::cout << "Вы получили защиту от смерти!" << std::endl;
	}
};