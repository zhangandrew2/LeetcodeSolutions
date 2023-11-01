#include <string>
#include <unordered_map>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> letters;
        for(int i = 0;i < s.length(); i++){
            if(letters.find(s[i]) == letters.end())
                letters[s[i]] = 1;
            else {letters[s[i]] += 1;}
        }
        for(int i = 0; i<t.length();i++){
            if (letters.find(t[i]) == letters.end() || letters[t[i]] == 0)
                return false;
            else letters[t[i]] -= 1;
        }
        if (t.length() == s.length())
            return true;
        return false;
    }
};

int main(){
    Solution tester;
    assert(tester.isAnagram("aacc","ccac") == 0);
    assert(tester.isAnagram("rat","car") == 0);
    assert(tester.isAnagram("abcdefgh","ceghabdf") == 1);
    assert(tester.isAnagram("jenny","nyjen") == 1);
    cout << "Complete";
}