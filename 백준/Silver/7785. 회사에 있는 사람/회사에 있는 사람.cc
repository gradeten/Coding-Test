#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    unordered_set<string> s;
    
    cin >> n;
    while(n--){
        string name, state;
        cin >> name >> state;
        if(state == "enter") s.insert(name);
        else s.erase(name);
    }
    
    vector<string> ans(s.begin(), s.end());
    sort(ans.begin(), ans.end(), greater<string>());
    for(auto x : ans) cout << x << '\n';
}