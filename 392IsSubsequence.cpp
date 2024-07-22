#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int cnt = 0;
        for(auto i: t){
            if(s[cnt] == i){
                cnt++;
            }
        }
        if (cnt == s.size())
            return true;
        return false;
    }
};

int main(){
    Solution tester;
    cout << tester.isSubsequence("abc","ahbgdc") << endl;
    cout << tester.isSubsequence("axc","ahbgdc");
}