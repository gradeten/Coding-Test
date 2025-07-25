#include <bits/stdc++.h>
using namespace std;

int m, n;
int l[1000005];
typedef long long ll;

bool solve(ll x){
    ll cur = 0;
    for(int i = 0; i < n; i++) cur += l[i] / x;
    return cur >= m;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;
    for(int i = 0; i < n; i++) cin >> l[i];
    sort(l,l+n);
    
    ll st = 1;
    ll en = 1000000000;
    
    if (!solve(1)) {
        cout << 0;
        return 0;
    }
    
    while(st < en){
        ll mid = (st + en + 1)/2;
        if (solve(mid)) st = mid;
        else en = mid - 1;
    }
    
    cout << st;
}