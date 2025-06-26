#include <bits/stdc++.h>
using namespace std;

int n;
int w[100005];
int ans = 0;

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> w[i];
    
    sort(w, w + n); 

    for(int i = 1; i <= n; i++){
        ans = max(w[n-i] * i, ans);
    }

    cout << ans;
}
