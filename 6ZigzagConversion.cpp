#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string res = "";
        vector<string> rows(numRows,"");
        int curr_row = 0;
        bool inc = true;
        if(numRows == 1){
            return s;
        }
        for(int i =0;i<s.size();i++){
            rows[curr_row] += s[i];
            if(curr_row == numRows-1 || (curr_row == 0 && !inc)){
                inc = !inc;
            }
            inc ? curr_row++ : curr_row--;
        }
        for(int i = 0; i < numRows;i++){
            res += rows[i];
        }
        return res;
    }
};

int main(){
    Solution tester;
    assert(tester.convert("PAYPALISHIRING",3) == "PAHNAPLSIIGYIR");
    assert(tester.convert("PAYPALISHIRING",4) == "PINALSIGYAHRPI");
    assert(tester.convert("A",1) == "A");
    cout<< "tests passed!";
}