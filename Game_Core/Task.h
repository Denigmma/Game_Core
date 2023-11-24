#pragma once
class Task : public Cell {
public:
	void performAction(Player& player) override {
		//int randomCellType = dis(gen);
		int num1 = std::rand() % 100;
		int num2 = std::rand() % 100;
		int result = num1 + num2;

		std::cout << "������ �������������� ������: " << num1 << " + " << num2 << " = ? ";
		std::cout << result << std::endl;
		int answer;
		std::cin >> answer;

		if (answer == result) {
			flag = true;
			actionlogic(player, 1);
		}
		else {
			flag = false;
			actionlogic(player, -3);
		}
	}

	void printDescription() const override {
		if (flag == true) {
			std::cout << "�� ������������ �� 1 ������ ������" << std::endl;
		}
		else {
			std::cout << "�� ������������ �� 3 ������ �����" << std::endl;
		}
	}
};