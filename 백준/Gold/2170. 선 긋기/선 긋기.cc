#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    long long ans = 0;
    for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    
    sort(v.begin(), v.end());
    
    int start = v[0].first;
    int end = v[0].second;
    
    for(int i = 1; i < v.size(); i++){
        if (v[i].first <= end){
            end = max(end, v[i].second);
        }
        else{
            ans += end - start;
            start = v[i].first;
            end = v[i].second;
        }
    }
    
    ans += (end - start);
    
    cout << ans;
}