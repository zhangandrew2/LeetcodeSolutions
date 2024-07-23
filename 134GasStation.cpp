#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
         int diff = 0, totaldiff = 0, n = gas.size(), start = 0, delta = 0;
         for(int i = 0; i< n; i++){
            delta = gas[i] - cost[i];
            totaldiff += delta;
            diff += delta;
            if(diff < 0){
                diff = 0;
                start = i+1;
            }
         }
        return (totaldiff < 0) ? -1 : start;
    }
};

int main(){
    Solution tester;
    vector<int> gas = {1,2,3,4,5}, cost = {3,4,5,1,2};
    cout << tester.canCompleteCircuit(gas,cost) << endl;
    gas = {2,3,4};
    cost = {3,4,3};
    cout << tester.canCompleteCircuit(gas,cost);
}