#include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, a;
    cin >> n;
    int arr[n];
    
    for(int i = 0; i < n; i++) cin >> arr[i];
    cin >> a;
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        if (arr[i] == a) ans++;
    }
    
    cout << ans;
}