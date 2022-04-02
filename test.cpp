#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

class test
{
public:
    enum classEnum{
        one,
        two,
        three
    };
    
public:

    classEnum x{one};
};

// bool foundit(vector<vector<string>> v_board, string key){
//     for (vector<string> x : v_board)
//     {
//         if (count(x.begin(), x.end(), key))
//         {
//             continue;
//         }
//         else
//             return false;
//     }
//     return true;
// }

int main()
{
    // test Test1;
    // cout << Test1.x <<endl;

    
    // vector<vector<string>> v_board = {{"*", "*", "*"}, {"*", "*", "*"}, {"*", "*", "*"}};
    // string key{"*"};
    // bool found = foundit(v_board, key);
    // if(found){
    //     cout<<"found it"<<endl;
    // }
    // else{
    //     cout<<"not found it"<<endl;
    // }

    test ObjTest;
    if(ObjTest.x==test::one)
    {
        cout<<"has"<<endl;
    }

}