#include <iostream>
#include <algorithm>

int binary_search(int input[], int R){
    int L = 0, ans =-1; R--;

    while(L <= R){
        int mid = L + ((R-L) / 2);
        if(input[mid] > input[mid-1]) {
            ans = input[mid];
            L=mid+1;
        }
        else {
            R = mid-1;
        }
    }
    return ans;
}

int main()
{
    int input[] = {10,11,12,13,14,17,19,18,16,15};
    int input_size = sizeof(input) / sizeof(int);
    int binary_search_result = binary_search(input, input_size);
    if(binary_search_result != -1){
        std::cout << "Element founded at position: " << binary_search_result << std::endl;
    } else {
        std::cout << "Element not founded" << std::endl;
    }


    return 0;
}