#pragma once
class GameBoard {
public:
	GameBoard() {
		initializeBoard();
		initializeCellBoard();
	}
	void clearScreen() {
		system("cls");
	}

	void play() {
		Player player;

		while (true) {
			printBoard();
			int move;
			std::cout << "Введите количество клеток для перемещения (1-3): ";
			std::cin >> move;

			if (move >= 1 && move <= 3) {
				if (player.Geti() == SizeBoard::ROWS - 1 && player.Getj() + move >= SizeBoard::COLS) {
					end();
					break;
				}

				board[player.Geti()][player.Getj()] = '-';

				player.Setj(player.Getj() + move);

				if (player.Getj() >= SizeBoard::COLS) {
					int extraRows = player.Getj() / SizeBoard::COLS;
					player.Seti(player.Geti() + extraRows);
					player.Setj(player.Getj() % SizeBoard::COLS);
				}

				if (player.Geti() == SizeBoard::ROWS - 1 && player.Geti() == SizeBoard::COLS) {
					end();
					break;
				}

				system("cls");

				Cell& currentCell = *cellBoard[player.Geti()][player.Getj()];
				currentCell.performAction(player);
				currentCell.printDescription();
				board[player.Geti()][player.Getj()] = 'P';
			}
			else {
				system("cls");
				std::cout << "Неверное количество клеток. Введите число от 1 до 3." << std::endl;
			}
		}
	}

private:
	std::vector<std::vector<char>> board;
	std::vector<std::vector<Cell*>> cellBoard;

	void initializeBoard() {
		board = std::vector<std::vector<char>>(SizeBoard::ROWS, std::vector<char>(SizeBoard::COLS, '-'));
	}

	void initializeCellBoard() {
		cellBoard = std::vector<std::vector<Cell*>>(SizeBoard::ROWS, std::vector<Cell*>(SizeBoard::COLS, NULL));

		int prevRandomCellType = -1; // Инициализируем значение, которое не совпадает с возможными типами

		for (int roww = 0; roww < SizeBoard::ROWS; ++roww) {
			for (int coll = 0; coll < SizeBoard::COLS; ++coll) {

				std::random_device rd;
				std::mt19937 gen(rd());
				std::uniform_int_distribution<int> dis(0, 11);

				int randomCellType;
				do {
					randomCellType = dis(gen);
				} while (randomCellType == prevRandomCellType);
				prevRandomCellType = randomCellType;

				//std::cout << randomCellType << std::endl;

				switch (randomCellType) {
				case 0:
					cellBoard[roww][coll] = new Down();
					break;
				case 1:
					cellBoard[roww][coll] = new Next();
					break;
				case 2:
					cellBoard[roww][coll] = new Boost();
					break;
				case 3:
					cellBoard[roww][coll] = new Drop();
					break;
				case 4:
					cellBoard[roww][coll] = new Task();
					break;
				case 5:
					cellBoard[roww][coll] = new Died();
					break;
				case 6:
					cellBoard[roww][coll] = new Zero();
					break;
				case 7:
					cellBoard[roww][coll] = new X();
					break;
				case 8:
					cellBoard[roww][coll] = new health();
					break;
				case 9:
					cellBoard[roww][coll] = new Proverb;
					break;
				case 10:
					cellBoard[roww][coll] = new Trigonom();
					break;
				case 11:
					cellBoard[roww][coll] = new Geometry();
					break;
				}
			}
		}
	}

	void printBoard() const {
		for (int row = 0; row < SizeBoard::ROWS; ++row) {
			for (int col = 0; col < SizeBoard::COLS; ++col) {
				std::cout << std::setw(2) << board[row][col] << ' ';
			}
			std::cout << std::endl;
		}
	}
};