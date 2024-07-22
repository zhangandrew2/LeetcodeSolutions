#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int maxright = matrix[0].size()-1, maxleft = 0, maxtop = 0, maxbot = matrix.size()-1;
        vector<int> list;
        int x = 0, y = 0, cnt = 0;
        if(matrix.empty())
            return {};
        int size = matrix.size() * matrix[0].size();
        while (maxright >= maxleft && maxbot >= maxtop){
            while (x <= maxright){
                list.push_back(matrix[y][x]);
                x++;
                cnt++;
            }
            maxtop++;
            x--;
            y++;
            while(y <= maxbot){
                list.push_back(matrix[y][x]);
                y++;
                cnt++;
            }
            y--;
            x--;
            maxright--;
            while(x >= maxleft && cnt < size){
                list.push_back(matrix[y][x]);
                x--;
                cnt++;
            }
            x++;
            y--;
            maxbot--;
            while(y >= maxtop && cnt < size){
                list.push_back(matrix[y][x]);
                y--;
                cnt++;
            }
            y++;
            x++;
            maxleft++;
        }
        return list;
    }
};

int main(){
    Solution tester;
    vector<vector<int>> matrix = {
        {1,2,3,4},{5,6,7,8},{9,10,11,12}
    };
    vector<int> ans = tester.spiralOrder(matrix);
    for(auto x: ans){
        cout << x << ",";
    }
}