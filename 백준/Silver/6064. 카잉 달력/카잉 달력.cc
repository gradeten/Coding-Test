#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        
        x--, y--;
        
        int ans = -1;
        int lcm = m / gcd(m,n) * n;
        
        for(int i = x; i < lcm; i+= m){
            if (i % n == y){
                ans = i + 1;
                break;
            }
        }
        
        cout << ans << '\n';
    }
}