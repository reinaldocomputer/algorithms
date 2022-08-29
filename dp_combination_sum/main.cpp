#include <iostream>
#define SIZE 3

/*
    Given the target value N and array of allowed numbers, count ways to write N as the sum of those numbers.

    Example:
    nums = [1,2,3]
    N = 4
    --
    1+1+1+1
    1+1+2
    1+2+1
    2+2
    1+3
    2+1+1
    3+1
    --
    Answer = 7

    results[0] = 1
    results[1] = 1
    results[2] = results[1] + results[0] = 2
    results[3] = results[2] + results[1] + results[0] = 4
    results[4] = results[3] + results[2] + results[1] = 7
    
    results[1] = 1
    results[2] = (1+1) + (2)
    results[3]  = (1+1+1) + (2+1) | 1+2 | 0+3
    results[4] =  (1+1+1+1) + (2+1+1) + (1+2+1) + (0+3+1) | (1+1+2) + (2+2) | (1+3)
*/
int combinationSum(int nums[], int N){
    int results[N+1];
    for(int i=1;i<=N;i++)results[i]=0;
    results[0] = 1;
    for(int i=1; i <= N; i++){
        for(int j=0;j<SIZE;j++){
            if(i-nums[j] >=0){
                results[i]+=results[i-nums[j]];
            }
        }
    }
    return results[N];
}
int main()
{
    int nums[SIZE] = {1,2,3};
    int N = 4;
    std::cout<<combinationSum(nums, N)<<std::endl;
    return 0;
}