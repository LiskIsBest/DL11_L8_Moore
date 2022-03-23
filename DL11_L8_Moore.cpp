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
enum players {first, second};
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

    void setToken(int x,players player)
    {
        static vector<int> col{0,0,0};
        switch(player){
            case first:
                v_board[x-1][2-col[x-1]] = 'D';
                col[x-1]++;
                break;
            case second:
                v_board[x-1][2-col[x-1]] = 'M';
                col[x-1]++;
                break;
        }


    }

    vector<vector<char>> getVector()
    const {
        return v_board;
    }

    void showBoard()
    const {   
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

/* here darien here. working on win check, try all equal thingy vector method
google it if you have to.
*/
bool winCheck(vector<vector<char>> v_board)
{
    for(int y{0}; y<v_board.size();y++)
    {
        if(v_board[y][0]==v_board[y][1] && v_board[y][1]==v_board[y][2])
            return true;
        else if()
        {}
    }



    return false;
}

int main()
{
    bool running = true;
    while(running){

        Board gameBoard;


        int choice{0};
        cout<<"Welcome to connect 3. The two player tokens are D and M. D goes first.\nSelect column numbers 1, 2, or 3 to choose a column.\n"<<endl;
        gameBoard.showBoard();
        players whichPlayer{first};
        while(!winCheck)
        {
            switch (whichPlayer)
            {
                case first:
                    int choice{0};
                    cout<<"Player 1(D) choose a column(1-3, 0 to quit): ";
                    cin >> choice;
                    if(choice = 0)
                        break;
                    gameBoard.setToken(choice,whichPlayer);
                    whichPlayer=second;
                    break;
                case second:
                    int choice{0};
                    cout<<"Player 2(M) choose a column(1-3, 0 to quit): ";
                    cin >> choice;
                    if(choice = 0)
                        break;
                    gameBoard.setToken(choice,whichPlayer);
                    whichPlayer=first;
                    break;
            }
        }
        
        running = false;
    }


    // Board one;
    // one.getVec();
    // one.setTurn(1);
    // cout<<endl;
    // one.getVec();

    return 0;
}
