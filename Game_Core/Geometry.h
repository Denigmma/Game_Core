#pragma once

class Geometry : public Cell {
public:
	void performAction(Player& player) override {
		std::cout << "О чем гласит Теорема Птолемея? " << std::endl;
		std::cout << "1) Для любого вписанного четырехугольника произведение его диагоналей\n равно сумме произведения каждой пары противоположных сторон" << std::endl;
		std::cout << "2) В любом треугольнике сумма внутренних углов равна 180`" << std::endl;
		std::cout << "3) Угол между касательной и хордой, проведенной через точку касания,\n равен половине угловой величины дуги, заключенной между ними." << std::endl;
		std::cout << "4) Если две параллельные прямые пересечены секущей, то соответственные углы равны." << std::endl;

		int contans, conttrue1 = 1;
		std::cin >> contans;

		if (conttrue1 == contans) {
			flagGeometry = true;
			actionlogic(player, 2);
		}
		else {
			flagGeometry = false;
			actionlogic(player, -2);
		}
	}
	void printDescription() const override {
		if (flagGeometry == true) {
			std::cout << "Неужели вы учитесь на матмехе? Птолемей гордится вами!\n Вы продвинулись на 2 клетки вперед" << std::endl;
		}
		else {
			std::cout << "Стыдно такое не знать... Партия забрть у вас один миска рис!\n Вы продвинулись на 1 клетку назад" << std::endl;
		}
	}
private:
	bool flagGeometry;
};