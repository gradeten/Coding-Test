#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, a, b;
    cin >> n >> a >> b;
    
    int ans = 0;
    while(a != b){
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        ans++;
    }
    cout << ans;
}