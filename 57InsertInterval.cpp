#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    //first find interval which includes newInterval's start
    //find which interval that includes newInterval's end
    //if start is within interval and end is too, merge start interval to end interval
    //if start isn't in interval and end isn't either
    //if 
    int newstart = newInterval[0],newend = newInterval[1];
    int currstart, currend;
    bool startfound = false, startininterval;
    for(int i = 0;i<intervals.size()-1;i++){
        currstart = intervals[i][0];
        currend = intervals[i][1];
        if(!startfound){
            if(newstart >= currstart && newstart <= currend){
                startfound = true;
                startininterval = true;
                //case of consecutive intervals for newstart and newend
                if(newend > currend && newend < intervals[i+1][0]){
                    intervals[i][1]= newend;
                    return intervals;
                }
            }
            else if(newstart > currend && newstart < intervals[i+1][0]){
                startfound = true;
                startininterval = false;
            }
        }
        if(startfound){

        }
    }
    }
};