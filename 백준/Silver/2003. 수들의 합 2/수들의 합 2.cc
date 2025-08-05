#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, m;
int arr[10005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    int ans = 0;
    ll tot = arr[0];
    int en = 0;
    for(int st = 0; st < n; st++){
        while(en < n && tot < m){
            en++;
            if (en != n) tot += arr[en];
        }
        if (tot == m) ans++;
        tot -= arr[st];
    }
    
    cout << ans;
}