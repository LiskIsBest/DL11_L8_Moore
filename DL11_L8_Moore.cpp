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
#include <algorithm>
#include <windows.h>
using std::cout, std::cin, std::endl, std::string, std::vector, std::all_of;

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

    Board::gState getGame()
        const
    {
        return game;
    }
    void setGame(gState newState)
    {
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
        if (v_board[0][0] != "*" && v_board[0][1] != "*" && v_board[0][2] != "*" && v_board[1][0] != "*" && v_board[1][1] != "*" && v_board[1][2] != "*" && v_board[2][0] != "*" && v_board[2][1] != "*" && v_board[2][2] != "*")
        {
            return cat;
        }
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

int main()
{
    float gameCount{0};
    float player1wins{0};
    float player2wins{0};
    float gameTies{0};

    cout << "Welcome to connect 3. The two player tokens are D and M. D goes first.\nSelect column numbers 1, 2, or 3 to choose a column.\n"
         << endl;

    char playAgain{' '};
    do
    {
        gameCount++;
        int choice{0};
        pState whichPlayer{first};
        Board gameBoard("D", "M");
        gameBoard.showBoard();
        while (gameBoard.getGame() == Board::loss)
        {
            vector<int> row{0, 0, 0};
            cin.clear();
            if (whichPlayer == first)
            {
                cout << "Player 1(M) choose a column(1-3, 0 to quit): ";
                whichPlayer = second;
            }
            else
            {
                cout << "Player 2(D) choose a column(1-3, 0 to quit): ";
                whichPlayer = first;
            }
            cin >> choice;
            if (choice == 0)
            {
                break;
            }
            while (choice < 1 || choice > 3 || row[choice - 1] >= 3)
            {
                cout << "\nChoice out of range, please retry\n\n";
                if (whichPlayer == first)
                    cout << "Player 1(D) choose a column(1-3, 0 to quit): ";
                else
                    cout << "Player 2(M) choose a column(1-3, 0 to quit): ";
                cin >> choice;
            }
            row[choice - 1]++;
            gameBoard.dropToken(choice, whichPlayer);
            gameBoard.setGame(gameBoard.gameCheck());
            cout << endl;
            gameBoard.showBoard();
            if (gameBoard.gameCheck() == Board::win)
            {
                switch (whichPlayer)
                {
                case second:
                    cout << "Player 1 wins!\n"
                         << endl;
                    player1wins++;
                    row.assign(3, 0);
                    break;
                case first:
                    cout << "Player 2 wins!\n"
                         << endl;
                    player2wins++;
                    row.assign(3, 0);
                    break;
                }
            }
            else if (gameBoard.gameCheck() == Board::cat)
            {
                cout << "Game is a tie. No one won.\n"
                     << endl;
                row.assign(3, 0);
                gameTies++;
            }
        }
        cout << "Play again? y/n: ";
        cin >> playAgain;
    } while (toupper(playAgain) != 'N');

    cout << "\nPlayer 1 won: " << player1wins << " times. " << ((player1wins / gameCount) * 100) << '%' << endl;
    cout << "Player 2 won: " << player2wins << " times. " << ((player2wins / gameCount) * 100) << '%' << endl;
    cout << "There was a tie: " << gameTies << " times. " << ((gameTies / gameCount) * 100) << '%' << endl;
    return 0;
}

/* TEST OUTPUT

Welcome to connect 3. The two player tokens are D and M. D goes first.
Select column numbers 1, 2, or 3 to choose a column.

1 2 3
-----
* * *
* * *
* * *
Player 1(M) choose a column(1-3, 0 to quit): 1

1 2 3
-----
* * *
* * *
M * *
Player 2(D) choose a column(1-3, 0 to quit): 2

1 2 3
-----
* * *
* * *
M D *
Player 1(M) choose a column(1-3, 0 to quit): 1

1 2 3
-----
* * *
M * *
M D *
Player 2(D) choose a column(1-3, 0 to quit): 2

1 2 3
-----
* * *
M D *
M D *
Player 1(M) choose a column(1-3, 0 to quit): 1

1 2 3
-----
M * *
M D *
M D *
Player 1 wins!

Play again? y/n: y
1 2 3
-----
* * *
* * *
* * *
Player 1(M) choose a column(1-3, 0 to quit): 1

1 2 3
-----
* * *
* * *
M * *
Player 2(D) choose a column(1-3, 0 to quit): 2

1 2 3
-----
* * *
* * *
M D *
Player 1(M) choose a column(1-3, 0 to quit): 3

1 2 3
-----
* * *
* * *
M D M
Player 2(D) choose a column(1-3, 0 to quit): 2

1 2 3
-----
* * *
* D *
M D M
Player 1(M) choose a column(1-3, 0 to quit): 1

1 2 3
-----
* * *
M D *
M D M
Player 2(D) choose a column(1-3, 0 to quit): 2

1 2 3
-----
* D *
M D *
M D M
Player 2 wins!

Play again? y/n: y
1 2 3
-----
* * *
* * *
* * *
Player 1(M) choose a column(1-3, 0 to quit): 1

1 2 3
-----
* * *
* * *
M * *
Player 2(D) choose a column(1-3, 0 to quit): 2

1 2 3
-----
* * *
* * *
M D *
Player 1(M) choose a column(1-3, 0 to quit): 1

1 2 3
-----
* * *
M * *
M D *
Player 2(D) choose a column(1-3, 0 to quit): 3

1 2 3
-----
* * *
M * *
M D D
Player 1(M) choose a column(1-3, 0 to quit): 2

1 2 3
-----
* * *
M M *
M D D
Player 2(D) choose a column(1-3, 0 to quit): 1

1 2 3
-----
D * *
M M *
M D D
Player 1(M) choose a column(1-3, 0 to quit): 3

1 2 3
-----
D * *
M M M
M D D
Player 1 wins!

Play again? y/n: y
1 2 3
-----
* * *
* * *
* * *
Player 1(M) choose a column(1-3, 0 to quit): 1

1 2 3
-----
* * *
* * *
M * *
Player 2(D) choose a column(1-3, 0 to quit): 2

1 2 3
-----
* * *
* * *
M D *
Player 1(M) choose a column(1-3, 0 to quit): 1

1 2 3
-----
* * *
M * *
M D *
Player 2(D) choose a column(1-3, 0 to quit): 2

1 2 3
-----
* * *
M D *
M D *
Player 1(M) choose a column(1-3, 0 to quit): 3

1 2 3
-----
* * *
M D *
M D M
Player 2(D) choose a column(1-3, 0 to quit): 1

1 2 3
-----
D * *
M D *
M D M
Player 1(M) choose a column(1-3, 0 to quit): 2

1 2 3
-----
D M *
M D *
M D M
Player 2(D) choose a column(1-3, 0 to quit): 3

1 2 3
-----
D M *
M D D
M D M
Player 1(M) choose a column(1-3, 0 to quit): 3

1 2 3
-----
D M M
M D D
M D M
Game is a tie. No one won.

Play again? y/n: n

Player 1 won: 2 times. 50%
Player 2 won: 1 times. 25%
There was a tie: 1 times. 25%
*/