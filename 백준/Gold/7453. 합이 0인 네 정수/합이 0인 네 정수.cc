#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
ll a[4005];
ll b[4005];
ll c[4005];
ll d[4005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
    
    vector<ll> ab; vector<ll> cd;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ab.push_back(a[i] + b[j]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cd.push_back(c[i] + d[j]);
        }
    }
    sort(ab.begin(), ab.end()); sort(cd.begin(), cd.end());
    
    ll ans = 0;
    for(auto i : ab){
        ans += upper_bound(cd.begin(), cd.end(), -i) - lower_bound(cd.begin(), cd.end(), -i);
    }
    cout << ans;
}