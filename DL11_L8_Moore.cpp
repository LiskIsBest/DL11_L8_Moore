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

class Board
{
private:
    char p1tok{'D'};
    char p2tok{'M'};

    vector<vector<char>> v_board;

public:
    Board()
    {
        v_board= {
        {'*', '*', '*'},
        {'*', '*', '*'},
        {'*', '*', '*'}};
    }

    void setTurn(int x,bool player)
    {
        static vector<int> col{0,0,0};
        switch(player){
            case true:
                v_board[x-1][2-col[x-1]] = 'D';
                col[x-1]++;
                break;
            case false:
                v_board[x-1][2-col[x-1]] = 'M';
                col[x-1]++;
                break;
        }


    }

    void showBoard()
    {   
        cout<<"1 2 3\n-----"<<endl;
        for (int y = 0; y < v_board.size(); y++)
        {
            for (int x = 0; x < v_board[y].size(); x++)
            {
                cout << v_board[x][y] << " ";
            }
            cout << endl;
        }
    }
};


int main()
{
    bool running = true;
    while(running){
        Board gameBoard;


        int choice{0};
        cout<<"Welcome to connect 3. The two player tokens are D and M. D goes first.\nSelect column numbers 1, 2, or 3 to choose a column.\n"<<endl;
        gameBoard.showBoard();

        
        // cin >> choice;
        // switch(choice){
        //     case 1:
                
        // }
        running = false;
    }


    // Board one;
    // one.getVec();
    // one.setTurn(1);
    // cout<<endl;
    // one.getVec();

    return 0;
}
