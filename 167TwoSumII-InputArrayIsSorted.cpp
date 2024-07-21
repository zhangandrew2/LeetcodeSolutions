#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size()-1;
        while (start < end){
            if (numbers[start] + numbers[end] == target)
                break;
            if(numbers[start] + numbers[end] > target){
                end--;
            }
            else{
                start++;
            }
        }
        vector<int> indices = {start+1, end+1};
        return indices;
    }
};

int main(){
    Solution tester;
    vector<int> nums = {2,7,11,15};
    vector<int> result = tester.twoSum(nums,9);
    cout << result[0] << "," << result[1];
}