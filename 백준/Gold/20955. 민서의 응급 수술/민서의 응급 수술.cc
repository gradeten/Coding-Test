#include <bits/stdc++.h>
using namespace std;
int n, m, u, v;
vector<int> adj[100005];
bool vis[100005];
int k = 0; // 연결된 컴포넌트 개수

void dfs(int cur){
    vis[cur] = true;
    for(int nxt : adj[cur]){
        if (vis[nxt]) continue;
        dfs(nxt);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i = 1; i <= n; i++){
        if (!vis[i]){
            dfs(i);
            k++;
        }
    }
    
    // 제거 간선: m + k - n => (n - 1 = m + k - 1 - ?)
    // 추가 간선: k - 1
    cout << m + k*2 - n - 1;
}