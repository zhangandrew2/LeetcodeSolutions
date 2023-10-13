#include <string>
#include <iostream>
#include <ctype.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int tailindex = s.length()-1;
        int headindex = 0;
        while (headindex < tailindex){
            if(!isalnum(s[headindex])){
                headindex++;
                continue;
            }
            if(!isalnum(s[tailindex])){
                tailindex--;
                continue;
            }
            if (toupper(s[headindex]) != toupper(s[tailindex])){
                return false;
            }
            headindex++;
            tailindex--;
        }
        return true;
    }
};

int main(){
    Solution tester;
    cout << tester.isPalindrome("race a car")<< endl;
    cout << tester.isPalindrome(" ") << endl;
    cout << tester.isPalindrome("a man, a plan, a canal: PAnama");
}