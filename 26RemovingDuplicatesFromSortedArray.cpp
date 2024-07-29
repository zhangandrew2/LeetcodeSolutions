#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int uniqueptr = 0;
        for(int i = 1;i < nums.size();i++){
            if (nums[i] != nums[uniqueptr]){
                nums[uniqueptr+1] = nums[i];
                uniqueptr++;
            }
        }
        return uniqueptr+1;
    }
};

int main(){
    Solution tester;
    vector<int> nums = {1,1,2};
    vector<int> expected = {1,2,2};
    assert(tester.removeDuplicates(nums) == 2 && nums == expected);
    nums = {0,0,1,1,1,2,2,3,3,4};
    expected = {0,1,2,3,4,2,2,3,3,4};
    assert(tester.removeDuplicates(nums) == 5 && nums == expected);
    cout << "tests passed";
}
