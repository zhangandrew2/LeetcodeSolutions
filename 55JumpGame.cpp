#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int targetindex = nums.size()-1;
        for(int i = nums.size()-2; i>=0;i--){
            if(i + nums[i] >= targetindex){
                targetindex = i;
            }
        }
        if (targetindex == 0)
            return true;
        return false;

    /*  Original slower solution

        vector<bool> jumpable(nums.size(),false);
        int i = 0;
        int n = nums.size();
        if(n==1)
            return true;
        while (i < n-1){
            for(int j = i+1;j<=i+nums[i];j++){
                if(j == n-1)
                    return true;
                jumpable[j] = true;
            }
            if(!jumpable[i+1])
                return false;
            i++;
        }
        return false; */
    }
};

int main(){
    Solution tester;
    vector<int> nums = {2,3,1,1,4};
    assert(tester.canJump(nums) == true);
    nums = {3,2,1,0,4};
    assert(tester.canJump(nums) == false);
    cout << "tests passed";
}