#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    static bool sortfunc(int i, int j){
        return (i>=j);
    }
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(),citations.end(),sortfunc);
        for(int i = n-1;i>=0;i--){
            if(citations[i] >= i+1){
                return i+1;
            }
        }
        return 0;
    }
};

int main(){
    Solution tester;
    vector<int> citations = {3,0,6,1,5};
    assert(tester.hIndex(citations) == 3);
    cout << "tests passed";
}