#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <random>
#include <thread>
#include <chrono>
#include "Player.h"
#include "Cell.h"
#include "SizeBoard.h"
#include "Proverb.h"
#include "Trigonom.h"
#include "Geometry.h"
#include "Down.h"
#include "Next.h"
#include "Boost.h"
#include "Drop.h"
#include "Task.h"
#include "Died.h"
#include "health.h"
#include "Zero.h"
#include "X.h"
#include "GameBoard.h"

int main() {
    setlocale(LC_ALL, "ru");
    GameBoard game;
    game.play();
    return 0;
}