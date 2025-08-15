#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second < b.second;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k, l;
    cin >> k >> l;
    
    unordered_map<string,int> m;
    for(int i = 1; i <= l; i++){
        string x; cin >> x;
        m[x] = i;
    }
    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    
    for(int i = 0; i < k && i < v.size(); i++){
        cout << v[i].first << '\n';
    }
}