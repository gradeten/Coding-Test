#include <bits/stdc++.h>
using namespace std;
int n;
int adj[105][105];
bool vis[105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> adj[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        fill(vis, vis + n, false);
        queue<int> q;
        q.push(i);
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            
            for(int nxt = 0; nxt < n; nxt++){
                if (adj[cur][nxt] && !vis[nxt]){
                    vis[nxt] = true;
                    q.push(nxt);
                }
            }
        }
        
        for(int j = 0; j < n; j++){
            cout << (vis[j] ? 1 : 0) << ' ';
        }
        cout << '\n';
    }
}