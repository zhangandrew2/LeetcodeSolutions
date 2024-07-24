#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        if (n > haystack.size() || n == 0){
            return -1;
        }
         for(int i = 0; i < haystack.size()-n+1;i++){
            if (haystack.substr(i,n) == needle)
                return i;
         }
         return -1;
    }
};

int main(){
    Solution tester;
    cout << tester.strStr("dsasadbutsad","sad") << endl;
    cout << tester.strStr("leetcode","leeto");
}