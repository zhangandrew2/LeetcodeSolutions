#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_set<string> set;
        unordered_map<char,string> map;
        int ptr1=0, ptr2=0, cnt = 0;
        string currword;
        while(ptr2 < s.size()){
            if(cnt >= pattern.size()){
                return false;
            }
            while(s[ptr2] != ' ' && ptr2 < s.size()){
                ptr2++;
            }
            currword = s.substr(ptr1, ptr2-ptr1);
            if(map.find(pattern[cnt]) == map.end()){
                map[pattern[cnt]] = currword;
                if(set.find(currword) != set.end()){
                    return false;
                }
                set.insert(currword);
            }
            else if(currword != map[pattern[cnt]]){
                return false;
            }
            ptr1= ptr2 + 1;
            ptr2++;
            cnt++;
        }
        if (cnt == pattern.size())
            return true;
        return false;
    }
};

int main(){
    Solution tester;
    string pattern = "abba";
    string s = "dog cat cat dog";
    assert(tester.wordPattern(pattern,s) == true);
    pattern = "abba";
    s = "dog cat cat fish";
    assert(tester.wordPattern(pattern,s) == false);
    pattern = "aaaa";
    s = "dog cat cat dog";
    assert(tester.wordPattern(pattern,s) == false);
    cout << "tests passed!";
}