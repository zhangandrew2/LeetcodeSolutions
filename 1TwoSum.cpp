#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int temp;
        vector<int> answer;
        unordered_map<int,int> valmap;
        for (int i=0;i<nums.size();i++){
            temp = target - nums[i];
            if (valmap.find(temp) != valmap.end()){
                answer.push_back(valmap[temp]);
                answer.push_back(i);
                return answer;
            }
            else{
                valmap[nums[i]] = i;
            }
        }
        return answer;
    }
};

int main(){
    Solution tester;
    int values[] = {3,2,4};
    vector<int> nums(values, values + sizeof(values)/sizeof(values[0]));
    int target = 6;
    for (int i =0;i< tester.twoSum(nums,target).size();i++){
    cout << tester.twoSum(nums,target)[i] << ", ";
    }
}