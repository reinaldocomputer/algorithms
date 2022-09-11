#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int partitionString(string s) {
        int cont = 1;
        string subs = "";
        subs+=s[0];

        for(int i=1;i<s.size();i++){
            if(subs.find(s[i]) == string::npos){
                subs+=s[i];
            } else {
                subs=s[i];
                cont++;
            }
        }
        return cont;
    }
};
