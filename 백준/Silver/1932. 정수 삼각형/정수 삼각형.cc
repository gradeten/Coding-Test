#include <bits/stdc++.h>
using namespace std;
int n;
int triangle[501][501];
int dp[501][501];

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++)
            cin >> triangle[i][j];
    
    for(int j = 0; j < n; j++)
        dp[n-1][j] = triangle[n-1][j];
    
    for(int i = n-2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            dp[i][j] = triangle[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
        }
    }
    
    cout << dp[0][0];
    return 0;
}