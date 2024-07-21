#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> rows(9);
        vector<unordered_set<int>> cols(9);
        vector<unordered_set<int>> boxes(9);

        for(int i = 0; i< 9;i++){
            for(int j = 0; j<9;j++){
                int boxnum = j/3 + 3*(i/3);
                if(board[i][j] == '.'){
                    continue;
                }
                int currval = board[i][j];
                if(rows[i].count(currval) || cols[j].count(currval) || boxes[boxnum].count(currval)){
                    return false;
                }
                rows[i].insert(currval);
                cols[j].insert(currval);
                boxes[boxnum].insert(currval);
            }
        }
        return true;
    }
};

int main(){
    Solution tester;
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}};
    cout << tester.isValidSudoku(board) << endl;
    board = {{'8','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}};
    cout << tester.isValidSudoku(board);

}