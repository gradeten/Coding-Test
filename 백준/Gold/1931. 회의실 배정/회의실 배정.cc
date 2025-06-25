#include <bits/stdc++.h>
using namespace std;
int n, a, b;
vector<pair<int,int>> v;
int ans = 0;
int t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v.push_back({b,a}); // 종료 시간, 시작 시간
    }
    
    sort(v.begin(), v.end());
    
    for(int i = 0; i < n; i++){
        if (t <= v[i].second){
            ans++;
            t = v[i].first;
        }
    }
    
    cout << ans;
}