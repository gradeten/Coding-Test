#include <bits/stdc++.h>
using namespace std;
vector<int> adj[505];
bool vis[505];

bool dfs(int cur, int par){
    vis[cur] = true;
    for(int nxt : adj[cur]){
        if (!vis[nxt]){
            if (dfs(nxt,cur)) return true; // 자식에서 사이클 발견
        }
        else if (nxt != par){
            return true; // 이미 방문했고 부모가 아닌데 다시 나오면 사이클
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, a, b;
    int t = 0;
    while(true){
        t++;
        int ans = 0;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        
        for(int i = 1; i <= n; i++) adj[i].clear();
        for(int i = 1; i <= n; i++) vis[i] = false;
        for(int i = 0; i < m; i++){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        for(int i = 1; i <= n; i++){
            if (!vis[i]){
                bool cycle = dfs(i,0);
                if (!cycle) ans++;
            }
        }
        
        cout << "Case " << t << ": ";
        if (ans == 0) cout << "No trees.\n";
        else if (ans == 1) cout << "There is one tree.\n";
        else cout << "A forest of " << ans << " trees.\n";
    }
}