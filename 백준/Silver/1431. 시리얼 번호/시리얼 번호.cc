#include <bits/stdc++.h>
using namespace std;

bool cmp(const string& a, const string& b){
    int asum = 0;
    int bsum = 0;
    for(int i = 0; i < a.size(); i++){
        if (isdigit(a[i])) asum += (a[i] - '0');
    }
    for(int i = 0; i < b.size(); i++){
        if (isdigit(b[i])) bsum += (b[i] - '0');
    }
    if (a.size() != b.size()){
        if (a.size() < b.size()) return true;
        else return false;
    }
    else if (asum != bsum){
        if (asum < bsum) return true;
        else return false;
    }
    return a < b;
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    sort(v.begin(), v.end(), cmp);
    
    for (auto s : v){
        cout << s << "\n";
    }
}