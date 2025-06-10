#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, n, m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<int> a(n); vector<int> b(m); int ans = 0;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++) cin >> b[i];
        
        sort(a.begin(), a.end()); sort(b.begin(), b.end());
        
        for(int i = 0; i < a.size(); i++){
            for(int j = 0; j < b.size(); j++){
                if (a[i] > b[j]) ans++;
                else break;
            }
        }
        cout << ans << "\n";
    }
}