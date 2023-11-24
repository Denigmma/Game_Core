#pragma once
class X : public Cell {
public:
	void performAction(Player& player) override {
		playTicTacToe();
		if (flag) {
			actionlogic(player, 0);
		}
		else
		{
			if (xwin) {
				actionlogic(player, 2);
				xwinp = xwin;
				xwin = false;
			}
			else {
				actionlogic(player, -2);
				xwinp = xwin;
			}
		}
	}
	void printDescription() const override {
		if (flag) {
			std::cout << "Ваша позиция не изменилась!" << std::endl;
		}
		else
		{
			if (xwinp) {
				std::cout << "Ваша позиция изменилась на 2 клетки вперед!" << std::endl;
			}
			else {
				std::cout << "Ваша позиция изменилась на 2 клетки назад!" << std::endl;
			}
		}
	}
	//текущее состояние игровой доски
	void printTicTacToeBoard(const std::vector<std::vector<char>>& board) const {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				std::cout << board[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}
	// проверк, заполнена ли игровая доска 
	bool isTicTacToeBoardFull(const std::vector<std::vector<char>>& board) const {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (board[i][j] == Null) {
					return false;
				}
			}
		}
		return true;
	}
	// проверка, завершена ли игра 
	bool isTicTacToeGameOver(const std::vector<std::vector<char>>& board, char mark) const {
		// строки и столбцы и диагонали на победу
		for (int i = 0; i < 3; ++i) {
			if (board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) {
				return true; // в строке
			}
			if (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark) {
				return true; // в столбце
			}
		}
		if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) {
			return true; // на диагонали
		}
		if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark) {
			return true; // на диагонали
		}
		return false;
	}
	// ход компьютера
	void computerTicTacToeMove(std::vector<std::vector<char>>& board) {
		std::vector<std::pair<int, int>> NullCells;


		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (board[i][j] == Null) {
					NullCells.push_back({ i, j });
				}
			}
		}

		if (NullCells.empty()) {
			return; // нет пустых клеток
		}

		// случайный ход
		std::pair<int, int> randomCell = NullCells[rand() % NullCells.size()];
		board[randomCell.first][randomCell.second] = O_MARK;
	}

	// запуск игрового процесса
	void playTicTacToe() {
		std::vector<std::vector<char>> ticTacToeBoard(3, std::vector<char>(3, Null));
		char currentPlayer = X_MARK;
		bool gameOver = false;

		while (!gameOver) {
			printTicTacToeBoard(ticTacToeBoard);

			if (currentPlayer == X_MARK) {
				int row, col;
				std::cout << "Ход игрока X. Введите координаты (строка и столбец (от 1 до 3)): ";
				std::cin >> row >> col;
				row -= 1;
				col -= 1;
				if (row >= 0 && row < 3 && col >= 0 && col < 3 && ticTacToeBoard[row][col] == Null) {
					ticTacToeBoard[row][col] = X_MARK;
					gameOver = isTicTacToeGameOver(ticTacToeBoard, X_MARK);
					currentPlayer = O_MARK;
				}
				else {
					std::cout << "Неверные координаты. Попробуйте снова." << std::endl;
				}
			}
			else {
				std::cout << "Ход игрока O (компьютера)..." << std::endl;
				computerTicTacToeMove(ticTacToeBoard);
				gameOver = isTicTacToeGameOver(ticTacToeBoard, O_MARK);
				currentPlayer = X_MARK;
			}

			if (isTicTacToeBoardFull(ticTacToeBoard) && !gameOver) {
				printTicTacToeBoard(ticTacToeBoard);
				std::cout << "Ничья!" << std::endl;
				gameOver = true;
				flag = true;
			}
		}

		printTicTacToeBoard(ticTacToeBoard);
		if (isTicTacToeGameOver(ticTacToeBoard, X_MARK)) {
			std::cout << "Вы, игрок X, победили! " << std::endl;
			xwin = true;
		}
		else {
			std::cout << "Игрок O (компьютер) выиграл!" << std::endl;
			xwin = false;
		}
	}

private:
	const int BOARD_SIZE = 3;
	const char Null = '-';
	const char X_MARK = 'X';
	const char O_MARK = 'O';
	bool xwin, xwinp;
	int io, jo;
};