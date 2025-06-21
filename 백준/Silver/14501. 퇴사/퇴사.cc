#include <bits/stdc++.h>
using namespace std;
int n;
int t[20];
int p[20];
int d[20];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> t[i] >> p[i];
    }
    
    for(int i = n; i >= 1; i--){
        if (i + t[i] - 1 <= n)
            d[i] = max(d[i+1], p[i] + d[i + t[i]]);
        else
            d[i] = d[i+1];
    }
    
    cout << d[1];
}