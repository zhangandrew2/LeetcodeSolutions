#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] != color)
            solve(image, sr, sc, color, image[sr][sc]);
        return image;
    }
    void solve(vector<vector<int>>& image, int sr, int sc, int color, int refcolor){
        if (sr < 0 || sc < 0 || sc >= image.size() || sr >= image[0].size() 
        || image[sr][sc] != refcolor){
            return;
        }
        image[sr][sc] = color;
        solve(image, sr+1, sc, color, refcolor);
        solve(image, sr-1, sc, color, refcolor);
        solve(image, sr, sc+1, color, refcolor);
        solve(image, sr, sc-1, color, refcolor);
    }
};

int main(){

}