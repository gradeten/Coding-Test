#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int e, s, m;
    cin >> e >> s >> m;
    if (e == 15) e = 0;
    if (s == 28) s = 0;
    if (m == 19) m = 0;
    
    int ans = 1;
    while(true){
        if (ans % 15 == e && ans % 28 == s && ans % 19 == m) break;
        ans++;
    }
    cout << ans;
}