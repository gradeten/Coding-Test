#include <bits/stdc++.h>
using namespace std;
int vis[100002];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < 100002; i++) vis[i] = -1;
    
    int N, K;
    cin >> N >> K;
    queue<int> Q;
    vis[N] = 0;
    Q.push(N);
    
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for (int nxt : {cur-1, cur+1, cur*2}){
            if (nxt < 0 || nxt > 100000) continue;
            if (vis[nxt] != -1) continue;
            vis[nxt] = vis[cur] + 1;
            Q.push(nxt);
        }
    }
    
    cout << vis[K];
    
}