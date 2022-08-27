#include <iostream>
#define row 3
#define column 4
#define INF 9999

int min(int a, int b){
    return a < b ? a : b;
}
void clearTable(int grid[row][column]){
    for(int i=0;i<row;i++)
        for(int j=0;j<column;j++)
            grid[i][j] = INF;
}
void getMin(int grid[row][column], int distance[row][column]){
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            if(i+1 < row){
                distance[i+1][j] = min(distance[i+1][j], distance[i][j]+grid[i+1][j]);
            }
            if(j+1 < column){
                distance[i][j+1] = min(distance[i][j+1], distance[i][j]+grid[i][j+1]);
            }
        }
    }
}
void printTable(int grid[row][column]){
    for(int i=0;i<row;i++){
        if(i!=0) std::cout<<std::endl;
        for(int j=0;j<column;j++)
            std::cout<<grid[i][j] << " ";
    }
}
int main()
{
    int grid[row][column] = {{3,2,1,3},{1,9,2,3},{9,1,5,4}};
    int distance[row][column];
    clearTable(distance);
    distance[0][0] = grid[0][0];
    getMin(grid, distance);
    printTable(distance);
    return 0;
}