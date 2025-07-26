#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, m;
int tree[1000005];

bool solve(ll x){
    ll cur = 0;
    for(int i = 0; i < n; i++){
        if (tree[i] > x) cur += (tree[i] - x);
    }
    return cur >= m;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> tree[i];
    sort(tree,tree+n);
    
    ll st = 0;
    ll en = 2000000000;
    
    while(st < en){
        ll mid = (st + en + 1 )/2;
        if (solve(mid)) st = mid;
        else en = mid - 1;
    }
    cout << st;
}