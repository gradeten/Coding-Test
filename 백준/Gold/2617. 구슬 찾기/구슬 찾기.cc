#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
vector<int> adj[105];
vector<int> rev[105];
int vis[105];

int bfs(int start, vector<int> graph[105]){
    fill(vis, vis + 105, 0);
    queue<int> q;
    q.push(start);
    vis[start] = 1;
    
    int cnt = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto nxt : graph[cur]){
            if (vis[nxt]) continue;
            vis[nxt] = 1;
            q.push(nxt);
            cnt++;
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int ad = bfs(i, adj);
        int re = bfs(i, rev);
        if (ad > n/2 || re > n/2) ans++;
    }
    
    cout << ans;
}