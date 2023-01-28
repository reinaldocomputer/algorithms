#include <iostream>
 
using namespace std;

int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

int main() {
    int n;
    
    cin >> n;
    
    while(n--){
        int F1, F2;
        cin >> F1 >> F2;
        cout << gcd(F1,F2) << endl; 
    }
 
    return 0;
}