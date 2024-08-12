#include <vector>
#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int productleftof = 1;
        int productrightof = 1;
        for(int i = 0;i < n;i++){
            ans[i] = productleftof;
            productleftof *= nums[i];
        }
        for(int i = n-1;i>=0;i--){
            ans[i] *= productrightof;
            productrightof *= nums[i];
        }
        return ans;
    }
};

int main(){
    Solution tester;
    vector<int> nums = {1,2,3,4};
    vector<int> expected = {24,12,8,6};
    assert(tester.productExceptSelf(nums) == expected);
    nums = {-1,1,0,-3,3};
    expected = {0,0,9,0,0};
    assert(tester.productExceptSelf(nums) == expected);
    cout << "tests passed";
}