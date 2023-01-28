#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector <int> players) {
    // Quicksort - Mid case nlogn 
    sort(players.begin(), players.end());
    int mid = players.size() / 2;
    return players[mid];

}

int main()
{
    int t;
    cin >> t;
    int count = 1;
    while(t--){
        int n;
        cin >> n;
        vector<int>players(n);
        for(int i=0;i < n; i++){
            cin >> players[i];
        }
        
        cout << "Case "<< count << ": " << solution(players) << endl;
        count++;
    }

    return 0;
}