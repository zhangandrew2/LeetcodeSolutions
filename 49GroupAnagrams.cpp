#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        string temp;
        vector<vector<string>> ordered;
        for (auto x: strs){
            temp = x;
            sort(temp.begin(),temp.end());
            umap[temp].push_back(x);
        }
        for(auto mappair: umap){
            ordered.push_back(mappair.second);
        }
        return ordered;
    }
};

int main(){
    Solution tester;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result = tester.groupAnagrams(strs);
    for ( auto& row: result){
        for(auto& entry: row){
            cout << entry << ",";
        }
        cout << endl;
    }
}