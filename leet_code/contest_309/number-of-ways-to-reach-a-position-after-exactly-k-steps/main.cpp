#include <iostream>
#include <vector>

using namespace std;

#define MAX_K 3000
#define ORIGIN 1000

unsigned long int S[MAX_K][MAX_K];

class Solution {
public:

    int auxOfWays(int startPos, int endPos, int k) {
        if(endPos >= MAX_K || startPos >= MAX_K) return 0;
        if(k == 0 && startPos == endPos){
            return 1;
        }
        if(k == 0) return 0;

        if(S[startPos-1][k-1] == -1){
            S[startPos-1][k-1] = auxOfWays(startPos-1, endPos, k-1);
        }
        
        if(S[startPos+1][k-1] == -1){
            S[startPos+1][k-1] = auxOfWays(startPos+1, endPos, k-1);
        }
        return S[startPos-1][k-1] + S[startPos+1][k-1];
    }

    int numberOfWays(int startPos, int endPos, int k) {
        for(int i=0;i<MAX_K;i++){
            for(int j=0;j<MAX_K;j++){
                S[i][j] = -1;
            }
        }
        return auxOfWays(startPos+ORIGIN, endPos+ORIGIN,k);
    }
    

};



int main()
{
    return 0;
}