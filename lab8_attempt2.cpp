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
#include <string>
using namespace std;

enum pState
{
    first = '1',
    second = '2'
};

// game state

class Board
{
public: // datatypes
    enum gState
    {
        win = 'w',
        cat = 't',
        loss = 'l',
    };

private:
    string p1tok{};
    string p2tok{};
    gState game;
    vector<vector<string>> v_board;

public: // methods

    // constructor
    Board(string p1, string p2)
    {
        v_board = {{"*", "*", "*"}, {"*", "*", "*"}, {"*", "*", "*"}};
        game = loss;
        p1tok = p1;
        p2tok = p2;
    }

    gState const getGame(){
        return game;
    }
    gState setGame(gState newState){
        game = newState;
    }

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
        if (gameCheck() == win || gameCheck() == cat)
        {
            row.assign(3, 0);
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

        return loss;
    }
};

void turn(int &choice, Board &gameBoard, pState whichPlayer)
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
    int gameCount{0};
	int player1wins{0};
	int player2wins{0};
	int gameTies{0};
    int choice{0};
    pState whichPlayer{first};
    Board gameBoard("D","M");
    gameBoard.showBoard();
    while(gameBoard.getGame() == Board::loss){
        switch (whichPlayer)
        {
        case first:
            turn(choice, gameBoard, whichPlayer);
            whichPlayer = second;
            break;
        case second:
            turn(choice, gameBoard, whichPlayer);
            whichPlayer = first;
            break;
        }
        if(gameBoard.getGame() == Board::cat){
            ++gameTies;
        }
        gameBoard.setGame(gameBoard.gameCheck());
        cout << endl;
        gameBoard.showBoard();
    }
        

    return 0;
}