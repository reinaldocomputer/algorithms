#include <iostream>
#include <stdio.h>

float binary_search_square_root(int value)
{
    float L = 0, R = value, mid;
    while(R-L > 0.000009)
    {
        mid = L + ((R-L)/2.0);
        if(mid*mid < value){
            L = mid;
        } else {
            R = mid;
        }
    }
    return mid;
}


int main()
{
    printf("%.2f", binary_search_square_root(225));

    return 0;
}