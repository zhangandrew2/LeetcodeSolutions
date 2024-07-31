#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1, curr = nums[0];
        for(int i = 1; i < nums.size();i++){
            if(cnt == 0){
                curr = nums[i];
                cnt++;
            }
            else if(nums[i] == curr){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return curr;
    }
};

int main(){
    Solution tester;
    vector<int> nums = {10,9,9,9,10};
    assert(tester.majorityElement(nums) == 9);
    nums = {2,2,1,1,1,2,2};
    assert(tester.majorityElement(nums) == 2);
    cout << "tests passed";
}