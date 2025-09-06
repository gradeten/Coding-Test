#include <bits/stdc++.h>
using namespace std;
int n, a, b;
vector<int> adj[55];
vector<int> ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while(true){
        cin >> a >> b;
        if (a == -1 && b == -1) break;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int i = 1; i <= n; i++){
        int dis[55];
        fill(dis, dis+55, -1);

        queue<int> q;
        q.push(i);
        dis[i] = 0;
        
        int mx = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto nxt: adj[cur]){
                if (dis[nxt] != -1) continue;
                dis[nxt] = dis[cur]+1;
                mx = max(mx,dis[nxt]);
                q.push(nxt);
            }
        }
        ans.push_back(mx);
        
    }
    
    int mn = *min_element(ans.begin(), ans.end());
    cout << mn << ' ' << count(ans.begin(), ans.end(), mn) << '\n';
    for(int i = 0; i < n; i++){
        if (ans[i] == mn) cout << i+1 << ' ';
    }
}