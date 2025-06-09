#include <bits/stdc++.h>
using namespace std;

bool cmp(const string& a, const string& b){
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    sort(v.begin(), v.end(), cmp);
    v.erase(unique(v.begin(), v.end()), v.end());
    for (auto s : v) cout << s << "\n";
    return 0;
}