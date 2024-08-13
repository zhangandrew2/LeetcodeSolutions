#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int ptr = 1, cnt = 1, start = 0;
        vector<string> ans;
        if(nums.size() == 0)
            return ans;
        if (nums.size() == 1){
            ans.push_back(to_string(nums[0]));
            return ans;
        }
        while (ptr <= nums.size()){
            if(ptr!=nums.size() && nums[ptr] == nums[ptr-1] + 1){
                cnt++;
            }
            else if(cnt > 1){
                ans.push_back(to_string(nums[start]) + "->" + to_string(nums[ptr-1]));
                start = ptr;
                cnt = 1;
            }
            else if(cnt == 1){
                ans.push_back(to_string(nums[start]));
                cnt = 1;
                start = ptr;
            }
            ptr++;
        }
        return ans;
    }
};

int main(){
    Solution tester;
    vector<int> nums = {0,1,2,4,5,7};
    vector<string> res = {"0->2","4->5","7"};
    assert(tester.summaryRanges(nums) == res);
    nums = {0,2,3,4,6,8,9};
    res = {"0","2->4","6","8->9"};
    assert(tester.summaryRanges(nums) == res);
    cout << "tests passed!";
}