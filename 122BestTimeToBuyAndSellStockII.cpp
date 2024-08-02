#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprof = 0;
        for(int i = 0; i< prices.size()-1; i++){
            if(prices[i+1] > prices[i]){
                maxprof += prices[i+1] - prices[i];
            }
        }
        return maxprof;
    }
};

int main(){
    Solution tester;
    vector<int> prices = {7,1,5,3,6,4};
    assert(tester.maxProfit(prices) == 7);
    cout << "tests passed";
}