#include <iostream>
#include <set>
#include <string>

using namespace std;

bool orderbyend(vector<int> &a, vector<int>&b){
    return a[1] < b[1];
}

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), orderbyend);
        
        multiset<int> result;
        result.insert(intervals[0][1]);

        for(int i=1;i< intervals.size();i++){
            multiset<int>::iterator lower= result.lower_bound(intervals[i][0]);
            multiset<int>::reverse_iterator it(lower);
            for(; it!= result.rend() && *it >= intervals[i][0];it++);
            if(it == result.rend()){
                result.insert(intervals[i][1]);
            } else{
                result.erase(next(it).base());
                result.insert(intervals[i][1]);
                
            }
        }
        return result.size();
    }
};