#include <iostream>
#include <vector>
#define NUMBER_OF_LETTERS 26
using namespace std;

class Letter {
    public:
    int initialPositiion;
    int endPosition;

    Letter(){
        this->initialPositiion = -1;
        this->endPosition = -1;
    }
};

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<Letter> letters(NUMBER_OF_LETTERS);
        for(int i=0;i<s.size();i++){
            int position = int(s[i]-'a');
            if(letters[position].initialPositiion == -1){
                letters[position].initialPositiion = i;
            } else {
                letters[position].endPosition = i;
            }
        }
        for(int i=0;i<letters.size();i++){
            if(letters[i].initialPositiion != -1){
                int distance_letter = letters[i].endPosition - letters[i].initialPosition - 1;
                if(distance_letter != distance[i]){
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}