#include <bits/stdc++.h>
using namespace std;
int n, a, b;
vector<int> adj[100005];
int parent[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int nxt : adj[cur]){
            if (parent[cur] == nxt) continue;
            parent[nxt] = cur;
            q.push(nxt);
        }
    }
    
    
    for(int i = 2; i <= n; i++){
        cout << parent[i] << '\n';
    }
}