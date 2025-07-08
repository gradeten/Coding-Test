#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        long long ans = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                ans += gcd(v[i],v[j]);
            }
        }
        cout << ans << '\n';
    }
}