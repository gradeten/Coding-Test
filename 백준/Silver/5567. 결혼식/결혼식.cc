#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
int ans = 0;
vector<int> adj[505];
int vis[505];
queue<int> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    fill(vis, vis+505, -1);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    q.push(1);
    vis[1] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto nxt : adj[cur]){
            if (vis[nxt] != -1) continue;
            if (vis[cur]+1 > 2) continue;
            q.push(nxt);
            vis[nxt] = vis[cur]+1;
            ans++;
        }
    }
    
    cout << ans;
}