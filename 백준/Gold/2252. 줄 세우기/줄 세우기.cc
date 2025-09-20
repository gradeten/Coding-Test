#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
vector<int> adj[32005];
int deg[32005];
queue<int> q;
vector<int> ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }
    
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
    
    for (auto x : ans) cout << x << ' ';
}