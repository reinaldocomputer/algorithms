#include <iostream>
#include <algorithm>

int binary_search(int input[], int value, int R){
    int L = 0, ans =-1; R--;

    while(L <= R){
        int mid = L + ((R-L) / 2);
        if(input[mid] >= value) {
            ans = input[mid];
            R = mid -1;
        }
        else {
            L = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int input[] = {10,50,30,20,15,12,31,33,22,7,4,1};
    int input_size = sizeof(input) / sizeof(int);
    std::sort(input, input+input_size);
    int binary_search_result = binary_search(input, 5, input_size);
    if(binary_search_result != -1){
        std::cout << "Element founded at position: " << binary_search_result << std::endl;
    } else {
        std::cout << "Element not founded" << std::endl;
    }


    return 0;
}