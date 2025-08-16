#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    unordered_map<string,string> mp;
    
    while(n--){
        string id, pwd;
        cin >> id >> pwd;
        mp[id] = pwd;
    }
    
    while(m--){
        string s; cin >> s;
        cout << mp[s] << '\n';
    }
}