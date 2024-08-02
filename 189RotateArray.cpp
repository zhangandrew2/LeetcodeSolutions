#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> lastk;
        k = k%nums.size();
        if (k == 0)
            return;
        for(int i =nums.size()-1;i >=nums.size()- k;i--){
            lastk.push_back(nums[i]);
        }
        for(int i=nums.size()-1;i>=k;i--){
            nums[i] = nums[i-k];
        }
        int cnt =0;
        for(int i = k-1; i>=0;i--){
            nums[i] = lastk[cnt];
            cnt++;
        }
    }
};

int main(){
    Solution tester;
    vector<int> nums = {-1,-100,3,99};
    vector<int> expected = {3,99,-1,-100};
    tester.rotate(nums,2);
    assert(nums == expected);
    nums = {1,2,3,4,5,6,7};
    expected = {5,6,7,1,2,3,4};
    tester.rotate(nums,3);
    assert(nums == expected);
    cout << "tests passed";
}