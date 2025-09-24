#include <bits/stdc++.h>
using namespace std;
int n, m, u, v;
vector<int> adj[32005];
int deg[32005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 1; i <= n; i++){
        if (deg[i] == 0) pq.push(i);
    }
    while(!pq.empty()){
        int cur = pq.top(); pq.pop();
        cout << cur << ' ';
        for(int nxt : adj[cur]){
            deg[nxt]--;
            if (deg[nxt] == 0) pq.push(nxt);
        }
    }
}