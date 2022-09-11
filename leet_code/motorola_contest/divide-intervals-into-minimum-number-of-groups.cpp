#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector< vector< vector<int> > > getSubsets(vector<vector<int>>& intervals){
    vector< vector< vector<int> > > subsets;
    int totalCombination = 1 << intervals.size();
    for(int i=0; i  < totalCombination; i++){
        vector< vector<int> > subset;
        for(int j=0;i<intervals.size();j++){
            if(i & 1<<j){
                subset.push_back(intervals[j]);
            }
        }
    }

    return subsets;
}

bool isValidSubset(vector< vector<int> > subset){
    for(int i=0;i<subset.size()-1;i++){
        if(subset[i][1] >= subset[i+1][0]){
            return false;
        }
    }
    return true;
}

vector< vector<int> > maxDisInterval(vector<vector<int>>& intervals){
        int index=0;
        int max=0;
        auto subsets = getSubsets(intervals);
        for(int i=0;i<subsets.size();i++){
            if(isValidSubset(subsets[i])){
                if(subsets[i].size() > max){
                    max = subsets[i].size();
                    index = i;
                }
            }
        }
        return subsets[index];
}

void removeIntervals(vector<vector<int>>& maxIntervals, vector<vector<int>>& intervals){
    for(int i=0;i<maxIntervals.size();i++){
        for(int j=0;j<intervals.size();j++){
            if(maxIntervals[i][0] == intervals[j][0] &&
               maxIntervals[i][1] == intervals[j][1]){
                intervals.erase(intervals.begin()+j);
                break;
               }
        }
    }
}

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int cont = 0;
        while(not intervals.empty()){
            auto maxInterval = maxDisInterval(intervals);
            removeIntervals(maxInterval, intervals);
            cont++;
        }
        return cont;
    }
};