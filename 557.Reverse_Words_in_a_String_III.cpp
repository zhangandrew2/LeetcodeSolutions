#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string temp = "";
        int start = 0;
        int end = 1;
        for(int i=0;i<s.length(); i++){
            if (s[i] == ' ' | i==s.length()-1){
                if (s[i]== ' ') end = i-1;
                else end = i;
                for(int j=end; j>=start ; j--){
                    temp+=s[j];  
                }
                s.replace(start, temp.length(),temp);
                start = i+1;
                temp = "";
            }
        }
        return s;
    }
};

int main(){
    Solution test;
    cout << test.reverseWords("Let's take LeetCode contest");
}