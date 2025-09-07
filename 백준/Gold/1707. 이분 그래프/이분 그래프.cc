#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k, v, e, a, b; cin >> k;
    while(k--){
        cin >> v >> e;
        
        vector<int> adj[200005];
        int color[200005]; fill(color,color + 200005, 0);
        queue<int> q;
        
        for(int i = 0; i < e; i++){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        int flag = true;
        for(int i = 1; i <= v; i++){
            if (color[i] == 0){
                q.push(i);
                color[i] = 1;
                while(!q.empty()){
                    int cur = q.front();
                    q.pop();
                    for(auto nxt : adj[cur]){
                        if (color[nxt] == 0){
                            color[nxt] = -color[cur];
                            q.push(nxt);
                        }
                        else if (color[nxt] == color[cur]){
                            flag = false;
                        }
                    }
                }
            }
        }
        
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
}