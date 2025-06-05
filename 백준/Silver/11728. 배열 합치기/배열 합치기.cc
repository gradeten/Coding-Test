#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n), b(m), v;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    
    int a_i = 0;
    int b_i = 0;
    
    while (a_i < n && b_i < m) {
        if (a[a_i] < b[b_i]) {
            v.push_back(a[a_i++]);
        } else {
            v.push_back(b[b_i++]);
        }
    }
    
    while(a_i < n) v.push_back(a[a_i++]);
    while(b_i < m) v.push_back(b[b_i++]);
    
    for(auto i : v){
        cout << i << " ";
    }
    
}