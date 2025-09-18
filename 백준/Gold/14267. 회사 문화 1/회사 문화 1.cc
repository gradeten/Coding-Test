#include <bits/stdc++.h>
using namespace std;
int n, m, a, u, w;
vector<int> adj[100005];
int good[100005];
int ans[100005];

void dfs(int cur, int total){
    ans[cur] = total + good[cur];
    for(int nxt : adj[cur]){
        dfs(nxt, ans[cur]);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a;
        if (i == 1) continue;
        adj[a].push_back(i);
    }
    
    for(int i = 0; i < m; i++){
        cin >> u >> w;
        good[u] += w;
    }
    
    dfs(1,0);
    
    for(int i = 1; i <= n; i++){
        cout << ans[i] << ' ';
    }
}