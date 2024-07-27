#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ptr1 = 0, ptr2=0, sum = nums[0], minlength = nums.size();
        bool solved = false;
        while (ptr2 < nums.size()){
            if (sum < target){
                ptr2++;
                if(ptr2 < nums.size())
                    sum+= nums[ptr2];
            }
            else{
                solved = true;
                if (ptr2-ptr1+1 < minlength){
                    minlength = ptr2 - ptr1 +1;
                }
                sum -= nums[ptr1];
                ptr1++;

            }
        }
        return solved ? minlength : 0;
    }
};

int main(){
    Solution tester;
    vector<int> numarr = {1,1,1,1,1,1,1,1};
    cout << tester.minSubArrayLen(11, numarr) << endl;
    numarr = {2,3,1,2,4,3};
    cout << tester.minSubArrayLen(7, numarr) << endl;
}