#include <bits/stdc++.h>
using namespace std;
int n, m, k, a;
bool know[55];
vector<int> adj[55];
vector<vector<int>> parties;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    cin >> k;
    while(k--){
        cin >> a;
        know[a] = true;
    }
    
    int l;
    for(int i = 0; i < m; i++){
        vector<int> party;
        cin >> l;
        for(int i = 0; i < l; i++){
            cin >> a;
            party.push_back(a);
        } 
        parties.push_back(party);
        
        for(int x = 0; x < l; x++){
            for(int y = x+1; y < l; y++){
                adj[party[x]].push_back(party[y]);
                adj[party[y]].push_back(party[x]);
            }
        }
    }
    
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if (know[i]) q.push(i);
    }
    
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto nxt : adj[cur]){
            if (know[nxt]) continue;
            know[nxt] = true;
            q.push(nxt);
        }
    }
    
    int ans = 0;
    for(auto& party : parties){
        bool canLie = true;
        for(auto person : party){
            if (know[person]){
                canLie = false;
                break;
            }
        }
        if (canLie) ans++;
    }
    
    cout << ans;
}