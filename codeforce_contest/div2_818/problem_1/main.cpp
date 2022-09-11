#include <iostream>
#include <vector>
#define MAX_N 101
using namespace std;
// B. Madoka and Underground Competitions

enum VALID{
    POINT = 0,
    CHAR_X= 1
};
void solution(int n, int k, int r, int c){
    if(n==1){
        cout << "X" << endl;
        return ;
    }

    if(n==2){
        cout << "XX" << endl;
        cout << "XX" << endl;
        return ;
    }

    int m[n+1][n+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            m[i][j] = POINT;
    m[r][c] = CHAR_X;

    vector<bool>columns(MAX_N,false);
    vector<bool>rows(MAX_N,false);
    rows[r] = true;
    columns[c] = true;

    int _i = 1, _j = 1;
    while(_i <= n && _j <=n){
        if(rows[_i] == false && columns[_j] == false){
            rows[_i] = true;
            columns[_j] = true;
            m[_i][_j] = CHAR_X;
        }
        _i++;_j++;
    }
    _i = _j = 0;
    for(int i=1;i<=n;i++){
        if(not rows[i]){
            _i = i;
            break;
        }
    }

    for(int j=1;j<=n;j++){
        if(not columns[j]){
            _j = j;
            break;
        }
    }

    m[_i][_j] = CHAR_X;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(m[i][j] == CHAR_X){cout << "X";}
            else {cout << ".";}
        }
        cout<<endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k,r,c;
        cin >> n >> k >> r >> c;
        solution(n,k,r,c);
    }

    return 0;
}