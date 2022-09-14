#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) { // 123,456
        string result(num1.size()+num2.size(),'0');  //6

        for(int i=num1.size()-1;i>=0;i--){
            int v1 = num1[i] - '0'; // 3
            for(int j=num2.size()-1;j>=0;j--){
                int v2 = num2[j] - '0'; // 6
                int pos = i+j+1; // 
                int value = v1*v2; 
                while(value > 0){ 
                    value += result[pos] - '0'; 
                    result[pos] = (value%10) + '0'; 
                    value /=10; 
                    pos--; 
                }
            }
        }
        while(1){
            if(result[0] != '0') break;
            result.erase(result.begin());
        }
        if(result.empty()) return string("0");
        return result;
    }
};

int main(){
    Solution a;
    cout << a.multiply("2","3") << endl;
    return 0;
}