#include <bits/stdc++.h>
using namespace std;
int n;
long long d[105][10];
long long mod = 1000000000;
long long answer = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    d[1][0] = 0;
    d[1][1] = 1; d[1][2] = 1; d[1][3] = 1; d[1][4] = 1; d[1][5] = 1; d[1][6] = 1; d[1][7] = 1; d[1][8] = 1; d[1][9] = 1;
    
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= 9; j++){
            if (j == 0) d[i][j] = d[i-1][j+1] % mod;
            else if (j == 9) d[i][j] = d[i-1][j-1] % mod;
            else d[i][j] = (d[i-1][j-1] + d[i-1][j+1]) % mod;
        }
    }
    
    for(int i = 0; i <= 9; i++) answer = (answer + d[n][i]) % mod;
    cout << answer;
}