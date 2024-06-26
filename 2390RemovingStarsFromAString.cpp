#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        stack<char> phrase;
        for(int i = 0;i < s.length();i++){
            if(s[i]== '*'){
                if(!phrase.empty()){
                    phrase.pop();
                }
            }
            else{   
                phrase.push(s[i]);
            }
        }
        string reversed;
        while (!phrase.empty()){
            reversed += phrase.top();
            phrase.pop();
        }
        string output;
        for(int i = reversed.length()-1 ; i>=0;i--){
            output += reversed[i];
        }
        return output;
    }
};
int main(){    
    Solution test;
    cout << "Program Output" << endl;
    cout << test.removeStars("leet**cod*e");
}