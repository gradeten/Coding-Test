#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        unordered_map<string, int> m;
        while(n--){
            string name, kind;
            cin >> name >> kind;
            m[kind]++;
        }
        int ans = 1;
        for(auto x : m) ans *= (x.second+1);
        cout << ans - 1 << '\n';
    }
}