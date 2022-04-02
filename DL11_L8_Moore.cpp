/*
Programmer:           Darien Moore
Assignment:           Lab 8
Topic:                arrays, vectors, connect-Xgame
File Name:            DL11_L8_Lastname.cpp
Course/Section:       COSC 1337; Section 11
Instructor:           Thayer
*/
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// player state
enum pState
{
	first = '1',
	second = '2'
};

// game state
enum gState
{
	win = 'w',
	cat = 't',
	loss = 'l',
};

//----------------------------------------------------------------------------
class Board
{
private:
	vector<vector<string>> v_board; // init game board

public:
	// tokens for players
	string p1tok{"D"};
	string p2tok{"M"};
	gState game;

	// constructor
	Board()
	{
		v_board = {{"*", "*", "*"}, {"*", "*", "*"}, {"*", "*", "*"}};
		game = cat;
	}

	// drop token
	void dropToken(int x, pState player)
	{

		// decides which row to place
		static vector<int> row{0, 0, 0};

		switch (player)
		{
		case first:
			v_board[x - 1][2 - row[x - 1]] = p1tok;
			row[x - 1]++;
			break;
		case second:
			v_board[x - 1][2 - row[x - 1]] = p2tok;
			row[x - 1]++;
			break;
		}
		if (row[0]==2&&row[1]==2&&row[2]==2){
			row.assign(3,0);
			game = cat;
		}
		else if (gameCheck() == win || gameCheck()==cat)
		{
			row.assign(3, 0);
		}
	}

	// getter board
	vector<vector<string>> getBoard()
		const
	{
		return v_board;
	}

	// show the board
	void showBoard()
		const
	{
		cout << "1 2 3\n-----" << endl;
		for (int y = 0; y < v_board.size(); y++)
		{
			for (int x = 0; x < v_board[y].size(); x++)
			{
				cout << v_board[x][y] << " ";
			}
			cout << endl;
		}
	}

	gState gameCheck()
	{
		
		// vertical check
		for (int x{0}; x < v_board.size(); x++)
		{
			if (v_board[x][0] == v_board[x][1] && v_board[x][1] == v_board[x][2] && (v_board[x][0] == p1tok || v_board[x][0] == p2tok))
				return win;
		}

		// horizontal check
		for (int y{0}; y < v_board.size(); y++)
		{
			if (v_board[0][y] == v_board[1][y] && v_board[1][y] == v_board[2][y] && (v_board[0][y] == p1tok || v_board[0][y] == p2tok))
				return win;
		}

		// left bottom to right top diag check
		if (v_board[0][0] == v_board[1][1] && v_board[1][1] == v_board[2][2] && (v_board[0][0] == p1tok || v_board[0][0] == p2tok))
			return win;

		// right bottom to left top diag check
		else if (v_board[2][0] == v_board[1][1] && v_board[1][1] == v_board[0][2] && (v_board[2][0] == p1tok || v_board[2][0] == p2tok))
			return win;
		for (vector<string> x : v_board)
		return loss;
	}
};

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

void turn(int &choice, Board &gameBoard, bool &running, pState whichPlayer)
{
	cin.clear();
	if (whichPlayer == first)
		cout << "Player 1(D) choose a column(1-3, 0 to quit): ";
	else
		cout << "Player 2(M) choose a column(1-3, 0 to quit): ";
	cin >> choice;
	if (choice == 0)
		return;
	while (choice < 1 || choice > 3)
	{
		cout << "\nanswer out of range, please retry\n\n";
		if (whichPlayer == first)
			cout << "Player 1(D) choose a column(1-3, 0 to quit): ";
		else
			cout << "Player 2(M) choose a column(1-3, 0 to quit): ";
		cin >> choice;
	}
	gameBoard.dropToken(choice, whichPlayer);
}

int main()
{
	bool running = true;

	cout << "Welcome to connect 3. The two player tokens are D and M. D goes first.\nSelect column numbers 1, 2, or 3 to choose a column.\n"
		 << endl;
	int gameCount{0};
	int player1wins{0};
	int player2wins{0};
	int gameTies{0};

	while (running)
	{

		Board gameBoard;
		int choice{0};

		gameBoard.showBoard();
		pState whichPlayer{first};
		// gState wonYet = gameBoard.gameCheck();
		while (gameBoard.game=loss)
		{
			switch (whichPlayer)
			{
			case first:
				turn(choice, gameBoard, running, whichPlayer);
				whichPlayer = second;
				break;
			case second:
				turn(choice, gameBoard, running, whichPlayer);
				whichPlayer = first;
				break;
			}
			if (choice == 0)
				goto end_game;
			if(gameBoard.game == cat){
				++gameTies;
			}
			gameBoard.game = gameBoard.gameCheck();
			cout << endl;
			gameBoard.showBoard();
		}

		if(gameBoard.game == cat){
			cout << "TIE GAME! NO ONE WON. :("<<'\n';
			++gameCount;
		}
		else if(whichPlayer == second)
		{
			cout << "PLAYER 1 WON!" << '\n';
			++player1wins;
			++gameCount;
		}
		else if(whichPlayer == first)
		{
			cout << "PLAYER 2 WON!" << '\n';
			++player2wins;
			++gameCount;
		}

		char again{};
		cout << "play again? y/n: ";
		cin >> again;
		if (tolower(again) == 'n')
			running = false;
		else
			running = true;
	}
	end_game:;
	return 0;
}

/* TEST OUTPUT


*/