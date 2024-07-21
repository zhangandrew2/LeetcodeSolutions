#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int i = 0, j = 0;
        vector<vector<int>> matrix(rowSum.size(),vector<int>(colSum.size(), 0));
        while(i < rowSum.size() && j < colSum.size()){
            int minim = min(rowSum[i], colSum[j]);
            matrix[i][j] = minim;
            rowSum[i] -= minim;
            colSum[j] -= minim;
            if (rowSum[i] == 0){
                i++;
            }
            if(colSum[j] == 0)
                j++;
        }
        return matrix;
    }
};

int main(){
    Solution tester;
    vector<int> rowsum = {3,8};
    vector<int> colsum = {4,7};
    vector<vector<int>> matrix = tester.restoreMatrix(rowsum,colsum);
    for(auto x:matrix){
        for (auto y:x){
            cout << y <<",";
        }
        cout << endl;
    }
}