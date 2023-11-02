#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarysearch(nums, 0, nums.size()-1,target);
    }
    int binarysearch(vector<int> nums, int start, int end, int target){
        if(start > end)
            return -1;
        int middle = start + (end - start) /2;
        if (target == nums[middle])
            return middle;
        if (target < nums[middle]){
            return binarysearch(nums, start, middle-1, target);
        }
        else {
            return binarysearch(nums, middle+1, end, target);
        }
    }
};

int main(){
    Solution tester;
    vector<int> vec1 = {-1,0,3,5,9,12};
    assert(tester.search(vec1, 9) == 4);
    cout << "complete";
}