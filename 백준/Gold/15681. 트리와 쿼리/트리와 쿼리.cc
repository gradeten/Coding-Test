#include <bits/stdc++.h>
using namespace std;
int n, r, q, u, v;
vector<int> adj[100005];
int dp[100005];

int dfs(int cur, int par){
    dp[cur] = 1;
    for(int nxt : adj[cur]){
        if (nxt == par){
            continue;
        }
        dp[cur] += dfs(nxt, cur);
    }
    return dp[cur];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> r >> q;
    for(int i = 0; i < n-1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(r,-1);
    
    for(int i = 0; i < q; i++){
        cin >> u;
        cout << dp[u] << '\n';
    }
}