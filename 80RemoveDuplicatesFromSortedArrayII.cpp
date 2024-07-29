#include <vector>
#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int dupcount = 1, ptrj = 0;
        for(int i = 1;i<nums.size();i++){
            if (nums[ptrj] == nums[i] && dupcount < 2){
                nums[ptrj+1] = nums[i];
                ptrj++;
                dupcount++;
            }
            else if(nums[ptrj] != nums[i]){
                nums[ptrj+1] = nums[i];
                ptrj++;
                dupcount = 1;
            }
        }
        return ptrj + 1;
    }
};

int main(){
    Solution tester;
    vector<int> nums = {1,1,1,2,2,3};
    vector<int> expected = {1,1,2,2,3,3};
    assert(tester.removeDuplicates(nums) == 5 && nums == expected);
    nums = {0,0,1,1,1,1,2,3,3};
    expected = {0,0,1,1,2,3,3,3,3};
    assert(tester.removeDuplicates(nums) == 7 && nums == expected);
    cout << "tests passed";

}