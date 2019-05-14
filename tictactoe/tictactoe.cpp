#include"pch.h"
#include<iostream>
#include<iomanip>

using namespace std; 

class TicTacToe {

private:
	enum Status { W, D, C };

	int board[3][3]; // 3x3 built in matrix for the board

public:
	TicTacToe() {

		// build the 3x3 board
		for (int i = 0; i < 3; i++)

			for (int j = 0; j < 3; j++)
				board[i][j] = ' ';
	}

	bool validMove(int x, int y) {

		// ensure the square entered is within 3x3 board

		return x >= 0 && x < 3 && y >= 0 && y < 3 && board[x][y] == ' ';

	}

	Status gameStatus() {

		int a;

		//verify for 3 in a row diagonally
		if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2])
			return W;

		else if (board[2][0] != ' ' && board[2][0] == board[1][1] && board[2][0] == board[0][2])
			return W;

		//verify for 3 in a row along rows 
		for (a = 0; a < 3; a++)
			if (board[a][0] != ' ' && board[a][0] == board[a][1] && board[a][0] == board[a][2])
				return W;

		//verify for 3 in a row along columns
		for (a = 0; a < 3; a++)
			if (board[0][a] != ' ' && board[0][a] == board[1][a] && board[0][a] == board[2][a])
				return W;
		
		// verify if board is full without a win
		for (int i = 0; i < 3; i++) {

			for (int j = 0; j < 3; j++) {

				if (board[i][j] == ' ')
					return C;
			}
		}
		return D;
	}

	void printBoard() {
		
		cout << "   0   1   2\n\n"; 
		
		for (int r = 0; r < 3; r++) {
			cout << r;
			for (int c = 0; c < 3; c++) {

				cout << setw(3) << static_cast<char>(board[r][c]);
				
				if (c != 2)
					cout << "|  ";
			}
			
			if (r != 2)
				cout << "\n___|___|___\n   |   |   \n";
		}
		cout << "\n\n";
	}

	void move() {

		printBoard();

		while (true) {

			if (xoMove('X'))
				break;

			else if (xoMove('O'))
				break;
		}
	}


	bool xoMove(int symbol) {

		int x, y;

		do {
			cout << "Player " << static_cast<char>(symbol) << " enter move: ";
			cin >> x >> y;

			cout << '\n';

		} while (!validMove(x, y)); // check for valid move

		board[x][y] = symbol; // print player's symbol on the board

		printBoard(); // print new board

		Status xoStatus = gameStatus();

		if (xoStatus == W) {

			cout << "Player " << static_cast<char>(symbol) << "wins\n";
			return true;
		}
		else if (xoStatus == D) {

			cout << "game is a draw \n";
			return true;
		}

		else
			return false;
	}

};

int main() {

	TicTacToe game;

	game.move();

	return 0;
}
