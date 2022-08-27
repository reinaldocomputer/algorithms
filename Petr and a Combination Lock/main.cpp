#include <iostream>

int main(){
    int n;
    std::cin >> n;

    int input[n];
    for(int i=0;i<n;i++) std::cin >> input[i];

    int totalCombination = 1 << n;

    for(int i=0; i < totalCombination; i++){
        int sum = 0;

        for(int j=0; j < n; j++){
            if(i & 1<<j) sum += input[j];
            else sum-= input[j];
        }

        if(sum % 360 == 0){
            std::cout << "YES" << std::endl;
            return 0;
        }
    }
    std::cout << "NO" << std::endl;

    return 0;
}