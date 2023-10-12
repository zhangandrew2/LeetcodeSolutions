#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int currlowest = prices[0];
        for (int i =1;i<prices.size();i++){
            if (prices[i] < currlowest)
                currlowest = prices[i];
            if(prices[i]-currlowest > max)
                max = prices[i]-currlowest;
        }
        return max;
    }
};

int main(){
    int test[] = {7,1,5,3,6,4};
    vector<int> prices (test, test + sizeof(test)/sizeof(int));
    Solution tester;
    cout << "profits: " << tester.maxProfit(prices);

}