#pragma once
#include "Player.h"
#include "SizeBoard.h"
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>

class Cell {
public:
    virtual void performAction(Player& player) = 0;
    virtual void printDescription() const = 0;
protected:
	friend void actionlogic(Player& player, int a);
	friend void end();
    bool flag;

};


void end() {
	int k = 0;
	while (k < 10) {
		k += 1;
		system("cls");
		std::cout << "Поздравляем, вы выиграли!" << std::endl;
		std::cout << "\033[42m\n";
		char confetti[] = { '*', '+', 'o', '#', '%', '$', '&' };
		int confettiCount = sizeof(confetti) / sizeof(confetti[0]);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 7; j++) {
				int randomConfetti = std::rand() % confettiCount;
				std::cout << confetti[randomConfetti] << ' ';
			}
			std::cout << std::endl;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

void actionlogic(Player& player, int a) {
    if (a < 0) {
        if (player.Getj() >= -a) {
            player.Setj(player.Getj() + a);
        }
        else {
            if (player.Geti() > 0) {
                player.Setj((SizeBoard::COLS + player.Getj()) + a);
                player.Seti(player.Geti() - 1);
            }
            else {
                player.Setj(0);
            }
        }
    }
    if (a > 0) {
        if (player.Getj() < SizeBoard::COLS - a) {
            if (player.Getj() + a < SizeBoard::COLS) {
                player.Setj(player.Getj() + a);
            }
        }
        else {
            if (player.Geti() + 1 < SizeBoard::ROWS) {
                player.Seti(player.Geti() + 1);
                player.Setj(player.Getj() + a - SizeBoard::COLS);
            }
        }
    }
    if (a == -(SizeBoard::COLS * SizeBoard::ROWS)) {
        player.Seti(0);
        player.Setj(0);
    }
    if (a == 0) {}
}
