#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int price[n];
        long long ans = 0;
        
        for(int i = 0; i < n; i++) cin >> price[i];
        
        int mx = price[n-1];
        for(int i = n-2; i >= 0; i--){
            if (price[i] < mx) ans += (mx - price[i]);
            else mx = price[i];
        }
        
        
        cout << ans << '\n';
    }
}