#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b;
    cin >> a >> b;
    
    int anum[a]; int bnum[b];
    for(int i = 0; i < a; i++) cin >> anum[i];
    for(int i = 0; i < b; i++) cin >> bnum[i];
    
    sort(anum,anum+a);
    sort(bnum,bnum+b);
    
    int ans = 0;
    vector<int> v;
    for(int i = 0; i < a; i++){
        if (!binary_search(bnum,bnum+b,anum[i])){
            ans++;
            v.push_back(anum[i]);
        }
    }
    
    if (ans == 0){
        cout << 0; return 0;
    }
    cout << ans << '\n';
    for(auto i : v) cout << i << ' ';
}