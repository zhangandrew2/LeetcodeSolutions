#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int> >& trust) {
        vector<int> trustcount(n+1,0);
        vector<int> zerocount(n+1,0);
        for(int i=0;i<trust.size();i++){
            trustcount[trust[i][1]] += 1;
            zerocount[trust[i][0]] +=1;
        cout<< "trustcount = " << trustcount[2] << endl;
        cout << "zero count = " << zerocount[2] << endl;
        }

        for (int i=1;i<=n;i++){
            if (trustcount[i] == n-1 && zerocount[i]==0){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    int n = 2;
    int arr[1][2] = {
    {1, 2}
    };
    vector<vector<int> > test;
    for (int i = 0; i < 1; ++i) {
        vector<int> innerVec;
        for (int j = 0; j < 2; ++j) {
            innerVec.push_back(arr[i][j]);
        }
        test.push_back(innerVec);
    }
    // for (int i = 0;i<3;i++){
    //         for (int j =0;j<2;j++){
    //         cout << test[i][j];
    //         }
    //         cout << endl;
    //     }
    // cout<< test.size();
    Solution tester;
    cout << tester.findJudge(n, test);
}