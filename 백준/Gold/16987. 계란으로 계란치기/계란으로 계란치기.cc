#include <bits/stdc++.h>
using namespace std;
int n, maxBroken, broken;
int s[8];
int w[8];

void func(int k){
    if (k == n){
        maxBroken = max(maxBroken, broken);
        return;
    }
    if (s[k] <= 0 || broken == n-1){
        func(k+1);
        return;
    }
    for(int i = 0; i < n; i++){
        if (i == k || s[i] <= 0) continue;
        s[k] -= w[i];
        s[i] -= w[k];
        if (s[k] <= 0) broken++;
        if (s[i] <= 0) broken++;
        func(k+1);
        if (s[k] <= 0) broken--;
        if (s[i] <= 0) broken--;
        s[k] += w[i];
        s[i] += w[k];
    }
}

int main (void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i] >> w[i];
    func(0);
    
    cout << maxBroken;
}