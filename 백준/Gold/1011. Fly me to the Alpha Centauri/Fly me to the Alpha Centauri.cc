#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        int x, y; cin >> x >> y;
        int dist = y - x;
        int n = sqrt(dist);
        
        if (dist == n * n){
            cout << 2 * n - 1 << '\n';
        }
        else if (dist <= n * n + n){
            cout << 2 * n << '\n';
        }
        else{
            cout << 2 * n + 1 << '\n';
        }
    }
    
}