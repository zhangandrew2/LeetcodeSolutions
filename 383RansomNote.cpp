#include <unordered_map>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
       unordered_map<char,int> map;
       for(int i = 0;i<magazine.size();i++){
        map[magazine[i]]++;
       }
       for(int i=0;i<ransomNote.size();i++){
        if(map.find(ransomNote[i]) == map.end() || map[ransomNote[i]] == 0){
            return false;
        }
        map[ransomNote[i]]--;
       } 
       return true;
    }
};

int main(){
    Solution tester;
    string ransomNote = "abc";
    string magazine = "cca";
    assert(tester.canConstruct(ransomNote,magazine) == false);
    ransomNote = "aceg";
    magazine = "gcebbca";
    assert(tester.canConstruct(ransomNote,magazine) == true);
    cout<< "tests passed!";
}