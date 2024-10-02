#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <cassert>
using namespace std;

/* separate a given string into messages of a limited # (int limit) of characters
    limited to less than 10000 characters in message,
    example input: "abcdefghijklmnop", limit = 9
    output "abcd<1/4>","efgh<1/4>","ijkl<1/4>","mnop<1/4>" */
class Solution {
public:
    int determineLength(string message, int limit){
        vector<int> sizes = {0,9,99,999,9999};
        int maxchars = 0;
        int i = 1;
        while(maxchars < message.size()){
            maxchars += (sizes[i]-sizes[i-1])*(limit-3-2*i) - sizes[i-1];
            if(maxchars < 0){
                return -1;
            }
            i++;
        }
        i--;
        int totalchars = 0;
        for(int j = 1; j < i; j++){
            totalchars += sizes[j]*(limit- 3- i - j);
        }
        int remainingchars = message.size() - totalchars;
        return remainingchars%(limit-3-2*i) == 0 ? remainingchars/(limit- 3- 2*i) : remainingchars/(limit-3-2*i) +1;
    }
    vector<string> splitMessage(string message, int limit) {
        vector<string> ans;
        int lines = determineLength(message,limit);
        int lineschars = to_string(lines).size();
        if(lines == -1){
            return {};
        }
        int ptr = 0, currlinechar = 1;
        vector<int> sizes = {9,99,999,9999};
        for(int i =1;i<=lines;i++){
            if(i == 10)
                currlinechar++;
            if(i == 100)
                currlinechar++;
            if (i == 1000)
                currlinechar++;
            ans.push_back(message.substr(ptr, limit-3- lineschars - currlinechar) + "<" + to_string(i) + "/" + to_string(lines) + ">");
            ptr+= limit-3- lineschars - currlinechar;
        }
        return ans;
    }
};

int main(){
    Solution tester;
    vector<string> res = tester.sepMessage(15,"ASDFASDFFasdfasdffASDFASDFFasdfasdffASDFASDFFasdfasdffASDFASDFFasdfasdffASDFASDFFasdfasdffASDFASDFFasdfasdffASDFASDFFasdfasdffASDFASDFFasdfasdffASDFASDFFasdfasdffASDFASDFFasdfasdffASDFASDFF");
    res = tester.sepMessage(9,"this is really a very awesome message");
    for(auto x:res){
        cout << x << endl;
    }
}