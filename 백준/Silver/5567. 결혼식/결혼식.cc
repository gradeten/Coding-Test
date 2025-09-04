#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> adj[505];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int vis[505];
    fill(vis, vis+505, -1);
    
    queue<int> q;
    q.push(1);
    vis[1] = 0;
    
    int ans = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (vis[cur] == 2) continue; 
        for (auto nxt : adj[cur]) {
            if (vis[nxt] != -1) continue;
            vis[nxt] = vis[cur] + 1;
            q.push(nxt);
            ans++;
        }
    }
    
    cout << ans;
}
