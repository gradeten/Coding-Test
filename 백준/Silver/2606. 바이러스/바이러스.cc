#include <bits/stdc++.h>
using namespace std;
int n, m, d1, d2;
vector<int> adj[105];
bool vis[105];
queue<int> q;
int ans = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> d1 >> d2;
        adj[d1].push_back(d2);
        adj[d2].push_back(d1);
    }
    
    q.push(1);
    vis[1] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto nxt : adj[cur]){
            if (vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = true;
            ans++;
        }
    }
    
    cout << ans;
}