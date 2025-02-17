#include <bits/stdc++.h>
using namespace std;
int vis[1000001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    fill (vis, vis+100001, -1);
    int n, k;
    cin >> n >> k;
    
    queue<int> Q;
    vis[n] = 0;
    Q.push(n);
    
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        
        if(cur*2 <= 100000 && vis[cur*2] == -1){
            vis[cur*2] = vis[cur];
            Q.push(cur*2);
        }
        
        for(int nxt : {cur-1, cur+1}){
            if (nxt < 0 || nxt > 100000) continue;
            if (vis[nxt] != -1) continue;
            vis[nxt] = vis[cur] + 1;
            Q.push(nxt);
        }
    }
    
    cout << vis[k];
}