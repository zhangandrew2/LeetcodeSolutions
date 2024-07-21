#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int x = 0, y = height.size()-1, maxArea = 0, currArea = 0, dist = height.size()-1, minh;
        while (x<y){
            minh = min(height[x], height[y]);
            currArea = dist * minh;
            if(currArea > maxArea){
                maxArea = currArea;
            }
            if (minh == height[x]){
                x++;
            }
            else{
                y--;
            }
            dist--;
        }
        return maxArea;
    }
};

int main(){
    Solution tester;
    vector<int> heights = {1,8,6,2,5,4,8,3,7};
    cout << tester.maxArea(heights);
}