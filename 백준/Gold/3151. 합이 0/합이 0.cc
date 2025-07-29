#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
int arr[10005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr,arr+n);
    
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            auto ub = upper_bound(arr + j + 1, arr + n, -arr[i] - arr[j]);
            auto lb = lower_bound(arr + j + 1, arr + n, -arr[i] - arr[j]);
            ans += (ub - lb);
        }
    }
    
    cout << ans;
}