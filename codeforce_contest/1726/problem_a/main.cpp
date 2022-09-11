#include <stack>
#include <vector>
using namespace std;


#define RIGHT 1
#define LEFT -1
#define ORIGIN 0

class Ball{
public:
    int column;
    int row;
    int origin;
     Ball(int column){
        row=0;
        this->column=column;
        this->origin=column;
     }
};

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int QTD_COLUMNS = grid[0].size();
        int BOTTOM = grid.size();
        vector<int> r(QTD_COLUMNS);

        stack<Ball> s;

        for(int i=0;i<QTD_COLUMNS;i++) s.push(Ball(i));
        
        bool right;
        while(not s.empty()){
            Ball c = s.top(); s.pop();

            //Ball to right direction
            if(grid[c.row][c.column] == RIGHT){
                if(c.column + 1 < QTD_COLUMNS &&
                   grid[c.row][c.column+1] == RIGHT
                ) right = true;
                if(c.column + 1 == QTD_COLUMNS){
                    r[c.origin] = -1;
                    continue;
                } 
            }
            //Ball to left direction
            if(grid[c.row][c.column] == LEFT){
                if(c.column -1 >= ORIGIN &&
                   grid[c.row][c.column-1] == LEFT
                ) {
                    right = false;
                }
                if(c.column-1 < 0){
                    r[c.origin] = -1;
                    continue;
                }
            }
            //Ball is trapped
            if(grid[c.row][c.column] == RIGHT &&
               c.column + 1 < QTD_COLUMNS &&
               grid[c.row][c.column+1] == LEFT
            ) {
                r[c.origin]=-1;
                continue;
            }

            //Ball is trapped
            if(grid[c.row][c.column] == LEFT &&
               c.column - 1 >= ORIGIN &&
               grid[c.row][c.column-1] == RIGHT
            ) {
                r[c.origin]=-1;
                continue;
            }
            
            if(right){
                c.column+=1;
                c.row+=1;
            } else {
                c.column-=1;
                c.row+=1;
            }

            //Bottom
            if(c.row == BOTTOM){
                r[c.origin]=c.column;
                continue;
            } else {
                s.push(c);
            }

        }

        return r;
        
    }
};

[
    [1,1,1,1,1,1]
    [-1,-1,-1,-1,-1,-1]
    [1,1,1,1,1,1]
    [-1,-1,-1,-1,-1,-1]
]