#include <bits/stdc++.h>
using namespace std;
int n, a, b;
vector<int> adj[100005];
int parent[100005];

void dfs(int cur){
    for(int nxt : adj[cur]){
        if (parent[cur] == nxt) continue;
        parent[nxt] = cur;
        dfs(nxt);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1);
    for(int i = 2; i <= n; i++){
        cout << parent[i] << '\n';
    }
}