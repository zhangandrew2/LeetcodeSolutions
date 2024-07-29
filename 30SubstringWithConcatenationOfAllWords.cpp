#include <vector>
#include <iostream>
#include <string>
#include <cassert>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        //iterate through s, look for n segments of strings in words
        //store words in hashmap<string, int>
        unordered_map<string,int> map;
        vector<int> result;
        int n = words[0].size();
        int words_size = words.size();
        for(auto x: words){
            map[x]++;
        }
        for(int offset = 0; offset < n; offset++){
            unordered_map<string, int> seen;
            int count = 0;
            for(int i = offset; i + n -1 < s.size();i += n){
                string sub = s.substr(i,n);
                auto itr = map.find(sub);
                if (itr == map.end()){
                    seen.clear();
                    count = 0;
                    continue;
                }
                
                seen[sub]++;
                count++;
                
                while(seen[sub] > itr->second){
                    string curr = s.substr(i- (count-1)* n, n);
                    seen[curr]--;
                    count--;
                }

                if(count == words_size){
                    result.push_back(i-(words_size -1)*n);
                }
            }
        }
        return result;
    }
};

int main(){
    Solution tester;
    vector<string> words = {"word","good","best","word"};
    vector<int> expected = {};
    assert(tester.findSubstring("wordgoodgoodgoodbestword",words) == expected);
    words = {"bar","foo","the"};
    expected = {6,9,12};
    assert(tester.findSubstring("barfoofoobarthefoobarman",words) == expected);
    cout << "tests passed";
}