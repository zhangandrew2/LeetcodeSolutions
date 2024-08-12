#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map;
        unordered_set<char> set;
        for(int i = 0;i<s.size();i++){
            if (map.find(s[i]) == map.end()){
                map[s[i]] = t[i];
                if(set.find(t[i]) != set.end()){
                    return false;
                }
                set.insert(t[i]);
            }
            s[i] = map[s[i]];
        }
        if (s == t){
            return true;
        }
        return false;
    }
};

int main(){
    Solution tester;
    assert(tester.isIsomorphic("doog","bggp") == true);
    assert(tester.isIsomorphic("paper","title") == true);
    assert(tester.isIsomorphic("dsbs","baba") == false);
    cout << "tests passed!";    
}