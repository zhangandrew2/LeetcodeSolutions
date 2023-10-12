#include <string>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> strstack;
        for(int i =0;i < s.size();i++){
            if(s[i] == '[' || s[i] == '{' || s[i] == '('){
                strstack.push(s[i]);
            }
            else{
                if (strstack.empty() || 
                (s[i] == ']' && strstack.top() != '[') || 
                (s[i] == '}' && strstack.top() != '{' ) ||
                (s[i] == ')' && strstack.top() != '(' )){
                    return false;
                }
                else strstack.pop();

            }
        }
        if(strstack.empty() == true){
            return true;
        }
        else return false;
    }
};


int main(){
    Solution tester;
    cout<< tester.isValid("(){{[]()[(]}}[]") << endl;
    cout<< tester.isValid("(){{[]()[()]}}[]");
}