vector<bool> removed_stones;
vector<int> rows, columns;

bool mysort(vector<int> &a, vector<int> &b){
    return (rows[a[0]] + columns[a[1]]) < (rows[b[0]] + columns[b[1]]);
}

class Solution {
private:
    bool removeStone(vector<int>&stone){
        if(rows[stone[0]] > 1 or columns[stone[1]] > 1){
            rows[stone[0]]--;
            columns[stone[1]]--;
            return true;
        }
        return false;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        removed_stones = vector<bool>(stones.size(), false);
        rows = vector<int>(100001);
        columns = vector<int>(100001);
        for(auto stone:stones){
            rows[stone[0]]++;
            columns[stone[1]]++;
        }
        sort(stones.begin(), stones.end(), mysort);
        int count = 0;
        for(auto stone:stones){
            if(removeStone(stone)) count++;
        }
        return count;
    }
};