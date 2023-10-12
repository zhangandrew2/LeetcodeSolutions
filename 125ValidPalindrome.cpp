#include <string>
#include <iostream>
#include <ctype.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length()<2)
            return true;
        int tailindex = s.length()-1;
        int headindex = 0;
        while (headindex < tailindex){
            while(!isalnum(s[headindex]) && headindex < s.length()-1){
                headindex++;
            }
            while(!isalnum(s[tailindex]) && tailindex > 0){
                tailindex--;
            }
            if (isalnum(s[headindex]) &&  isalnum(s[tailindex])){
                s[headindex] = toupper(s[headindex]);
                s[tailindex] = toupper(s[tailindex]);
                if (s[headindex] != s[tailindex])
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