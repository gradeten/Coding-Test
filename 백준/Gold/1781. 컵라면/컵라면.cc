#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, day, cup;
    vector<pair<int,int>> p;
    priority_queue<int,vector<int>, greater<int>> pq;
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> day >> cup;
        p.push_back({day,cup});
    }
    sort(p.begin(), p.end());
    
    for(int i = 0; i < n; i++){
        pq.push(p[i].second);
        if (pq.size() > p[i].first) pq.pop();
    }
    
    int ans = 0;
    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
    }

    cout << ans << '\n';
}