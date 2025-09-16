#include <bits/stdc++.h>
using namespace std;
int n, m, u, v, d;
vector<pair<int,int>> adj[1005];
bool vis[1005];

int dfs(int st, int des, int dis){
    vis[st] = true;
    if (st == des) return dis;
    
    for(auto nxt : adj[st]){
        if (vis[nxt.first]) continue;
        int result = dfs(nxt.first, des, dis + nxt.second);
        if (result != -1) return result;
    }
    
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n-1; i++){
        cin >> u >> v >> d;
        adj[u].push_back({v,d});
        adj[v].push_back({u,d});
    }
    
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        fill(vis,vis+1005,false);
        cout << dfs(u,v,0) << '\n';
    }
}