#include <vector>
#include <unordered_map>
#include <iostream>
#include <cassert>
using namespace std;

class RandomizedSet {
    unordered_map<int, int> map;
    vector<int> nums;
public:
    RandomizedSet() {
    }

    bool insert(int val) {
        if (map.find(val) == map.end()){
            nums.push_back(val);
            map[val] = nums.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(map.find(val) != map.end()){
            if(map[val] != nums.size()-1){
                nums[map[val]] = nums[nums.size()-1];
                map[nums[nums.size()-1]] = map[val];
            }
            nums.pop_back();
            map.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(){
    RandomizedSet* tester = new RandomizedSet();
    assert(tester->insert(1) == true);
    assert(tester->remove(2) == false);
    assert(tester->insert(2) == true);
    cout << "Random between 1 & 2: " << tester->getRandom() << endl;
    assert(tester->remove(1) == true);
    assert(tester->insert(2) == false);
    assert(tester->getRandom() == 2);
    cout << "tests passed";
}