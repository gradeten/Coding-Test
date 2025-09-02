#include <bits/stdc++.h>
using namespace std;
int n, m, v, d1, d2;
vector<int> adj[1005];
bool vis[1005];

void dfs1(){
    stack<int> s;
    s.push(v);
    while(!s.empty()){
        int cur = s.top();
        s.pop();
        if (vis[cur]) continue;
        vis[cur] = true;
        cout << cur << ' ';
        for(int i = 0; i < adj[cur].size(); i++){
            int nxt = adj[cur][adj[cur].size() - 1 - i];
            if (vis[nxt]) continue;
            s.push(nxt);
        }
    }
}

void dfs2(int cur){
    vis[cur] = true;
    cout << cur << ' ';
    for(auto nxt : adj[cur]){
        if (vis[nxt]) continue;
        dfs2(nxt);
    }
}

void bfs(){
    queue<int> q;
    q.push(v);
    vis[v] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for(auto nxt: adj[cur]){
            if(vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> v;
    for(int i = 0; i < m; i++){
        cin >> d1 >> d2;
        adj[d1].push_back(d2);
        adj[d2].push_back(d1);
    }
    
    for(int i = 1; i <= n; i++){
        sort(adj[i].begin(), adj[i].end());
    }
    
    dfs1(); // dfs2(v);
    cout << '\n';
    fill(vis+1, vis+n+1, false);
    bfs();
}