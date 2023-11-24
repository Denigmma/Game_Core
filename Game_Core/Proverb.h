#pragma once
#include "SizeBoard.h"
#include "Cell.h"

class Proverb : public Cell {
public:
	void performAction(Player& player) override {
		std::cout << "Продолжите песню, выбрав правильный ответ:" << std::endl;
		//std::cout << "Эта - игра, без сомнения. Обреченнных ждет ... " << std::endl;
		std::cout << "Он волен взять и поменять, строку и с ней ..." << std::endl;
		std::cout << "1) смысл жизни моей" << std::endl; \
			std::cout << "2) течение всех рек" << std::endl;
		std::cout << "3) смысл темы всей" << std::endl;
		std::cout << "4) цвет солнца" << std::endl;

		int contans, conttrue = 3;
		std::cin >> contans;

		if (contans == conttrue) {
			flag = true;
			actionlogic(player, 2);
		}
		else {
			flag = false;
			actionlogic(player, -1);
		}
	}
	void printDescription() const override {
		if (flag == true) {
			std::cout << "Да вы знаток! Вы продвинулись на 2 клетку вперед" << std::endl;
		}
		else {
			std::cout << "Стыдно такое не знать... Вы продвинулись на 1 клетку назад" << std::endl;
		}

	}
};