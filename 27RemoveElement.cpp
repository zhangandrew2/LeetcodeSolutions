#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (int i = 0;i < nums.size();i++){
            if(nums[i] == val){
                nums[i] = nums[nums.size() - 1];
                i--;
                nums.erase(nums.end()-1);
            }
        }
        return nums.size();
    }
};

int main(){
    Solution tester;
    vector<int> nums = {3,2,2,3};
    vector<int> expected = {2,2};
    tester.removeElement(nums,3);
    assert(nums == expected);
    nums = {0,1,2,2,3,0,4,2};
    expected = {0,1,4,0,3};
    tester.removeElement(nums,2);
    assert(nums == expected);
    cout << "tests passed";
}
