#include <iostream>
#include <vector>
#define lli unsigned long long int
std::vector<lli> fib_vec;

void fibonacci(){
    lli fib_it = 0;
    fib_vec.push_back(1);
    fib_vec.push_back(1);

    while(1){
        int current = fib_vec.size();
        fib_it = fib_vec[current-1] + fib_vec[current-2];
        if(fib_vec[current-1] > INT_FAST64_MAX){
            break;
        }
        fib_vec.push_back(fib_it);
    }
}

void print_fibonacci(){
    std::cout << "Fibonacci Sequence" << std::endl;
    for(int i=0;i < fib_vec.size();i++) std::cout <<"fib["<<i<<"]:"<< fib_vec[i]<< std::endl;
}
int main()
{
    fibonacci();
    print_fibonacci();
    return 0;
}