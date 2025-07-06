#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int l, p, v;
    int c = 1;
    
    while(true){
        cin >> l >> p >> v;
        if (l == 0 && p == 0 && v == 0) break;
        
        cout << "Case " << c << ": " << (v/p)*l + (v%p > l ? l : v%p) << '\n';
        c++;
    }
}