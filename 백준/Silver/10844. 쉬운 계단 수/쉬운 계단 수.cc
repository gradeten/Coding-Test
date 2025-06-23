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
    
    for(int i = 1; i <= 9; i++) d[1][i] = 1;
   
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