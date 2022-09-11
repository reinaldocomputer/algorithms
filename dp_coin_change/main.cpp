#include <iostream>

int min(int a, int b){return a < b ? a : b;}

int minCoins(int N, int value, int coins[])
{
    int results[value+1];
    for(int i=0;i<=value;i++) results[i] = INT32_MAX;
    results[0] = 0;
    for(int i=1;i<=value;i++){
        for(int j=0;j<N;j++){
            if(i-coins[j] >= 0){
                results[i] = min(results[i], results[i-coins[j]]+1);
            }
        }
    }
    return results[value];   
}

int main()
{
    int N=3, value=6;
    std::cin>>N>>value;
    int input[N];
    for(int i=0;i<N;i++)std::cin>>input[i];
    std::cout<<"Min coins: "<<minCoins(N, value, input)<<std::endl;
    return 0;
}