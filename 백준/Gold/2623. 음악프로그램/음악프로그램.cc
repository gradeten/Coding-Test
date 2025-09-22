#include <bits/stdc++.h>
using namespace std;
int n, m, t, pr, ne;
vector<int> adj[1005];
int deg[1005];
vector<int> ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    while(m--){
        cin >> t; cin >> pr;
        for(int i = 0; i < t-1; i++){
            cin >> ne;
            adj[pr].push_back(ne);
            deg[ne]++;
            pr = ne;
        }
    }
    
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if (deg[i] == 0) q.push(i);
    }
    
    while(!q.empty()){
        int cur = q.front(); q.pop();
        ans.push_back(cur);
        for(int nxt : adj[cur]){
            deg[nxt]--;
            if (deg[nxt] == 0) q.push(nxt);
        }
    }
    
    if (ans.size() != n){
        cout << 0;
    }
    else{
        for (auto x : ans) cout << x << '\n';
    }
}