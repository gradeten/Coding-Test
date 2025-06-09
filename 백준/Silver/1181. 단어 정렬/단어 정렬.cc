#include <bits/stdc++.h>
using namespace std;

bool cmp(const string& a, const string& b){
    if (a.size() != b.size()){
        return a.size() < b.size();
    }
    else{
        return a < b;
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<string> v;
    string s;
    while(n--){
        cin >> s;
        if (find(v.begin(), v.end(), s) == v.end()) v.push_back(s);
    }
    
    sort(v.begin(), v.end(), cmp);
    for (auto s : v) cout << s << "\n";
    return 0;
}