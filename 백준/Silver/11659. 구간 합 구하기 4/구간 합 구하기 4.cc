#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> prefix(n+1);

    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        prefix[i] = prefix[i-1] + x;
    }
    
    while(m--){
        int a,b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a-1] << "\n";
    }
}