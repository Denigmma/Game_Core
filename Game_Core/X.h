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
			std::cout << "���� ������� �� ����������!" << std::endl;
		}
		else
		{
			if (xwinp) {
				std::cout << "���� ������� ���������� �� 2 ������ ������!" << std::endl;
			}
			else {
				std::cout << "���� ������� ���������� �� 2 ������ �����!" << std::endl;
			}
		}
	}
	//������� ��������� ������� �����
	void printTicTacToeBoard(const std::vector<std::vector<char>>& board) const {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				std::cout << board[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}
	// �������, ��������� �� ������� ����� 
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
	// ��������, ��������� �� ���� 
	bool isTicTacToeGameOver(const std::vector<std::vector<char>>& board, char mark) const {
		// ������ � ������� � ��������� �� ������
		for (int i = 0; i < 3; ++i) {
			if (board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) {
				return true; // � ������
			}
			if (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark) {
				return true; // � �������
			}
		}
		if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) {
			return true; // �� ���������
		}
		if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark) {
			return true; // �� ���������
		}
		return false;
	}
	// ��� ����������
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
			return; // ��� ������ ������
		}

		// ��������� ���
		std::pair<int, int> randomCell = NullCells[rand() % NullCells.size()];
		board[randomCell.first][randomCell.second] = O_MARK;
	}

	// ������ �������� ��������
	void playTicTacToe() {
		std::vector<std::vector<char>> ticTacToeBoard(3, std::vector<char>(3, Null));
		char currentPlayer = X_MARK;
		bool gameOver = false;

		while (!gameOver) {
			printTicTacToeBoard(ticTacToeBoard);

			if (currentPlayer == X_MARK) {
				int row, col;
				std::cout << "��� ������ X. ������� ���������� (������ � ������� (�� 1 �� 3)): ";
				std::cin >> row >> col;
				row -= 1;
				col -= 1;
				if (row >= 0 && row < 3 && col >= 0 && col < 3 && ticTacToeBoard[row][col] == Null) {
					ticTacToeBoard[row][col] = X_MARK;
					gameOver = isTicTacToeGameOver(ticTacToeBoard, X_MARK);
					currentPlayer = O_MARK;
				}
				else {
					std::cout << "�������� ����������. ���������� �����." << std::endl;
				}
			}
			else {
				std::cout << "��� ������ O (����������)..." << std::endl;
				computerTicTacToeMove(ticTacToeBoard);
				gameOver = isTicTacToeGameOver(ticTacToeBoard, O_MARK);
				currentPlayer = X_MARK;
			}

			if (isTicTacToeBoardFull(ticTacToeBoard) && !gameOver) {
				printTicTacToeBoard(ticTacToeBoard);
				std::cout << "�����!" << std::endl;
				gameOver = true;
				flag = true;
			}
		}

		printTicTacToeBoard(ticTacToeBoard);
		if (isTicTacToeGameOver(ticTacToeBoard, X_MARK)) {
			std::cout << "��, ����� X, ��������! " << std::endl;
			xwin = true;
		}
		else {
			std::cout << "����� O (���������) �������!" << std::endl;
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