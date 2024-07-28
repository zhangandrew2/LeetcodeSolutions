#include <string>
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, maxlength = 0;
        vector<int> mapping(128, -1);
        while (right < s.size()){
            if(mapping[s[right]] < left){
                mapping[s[right]] = right;
                right++;
            }
            else{
                maxlength = (maxlength > right-left) ? maxlength : right-left;
                left = mapping[s[right]] + 1;
                mapping[s[right]] = right; 
                right++;
            }
        }
        return (maxlength > right-left) ? maxlength : right-left;
    }
};

int main(){
    Solution tester;
    assert(tester.lengthOfLongestSubstring("aab") == 2);
    assert(tester.lengthOfLongestSubstring("pwwkew")== 3);
    cout << "tests passed";
}