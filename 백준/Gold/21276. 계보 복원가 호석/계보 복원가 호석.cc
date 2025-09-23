#include <bits/stdc++.h>
using namespace std;
int n, m;
string x, y;

string name[1005];
int deg[1005];
vector<int> adj[1005];
unordered_map<string,int> id;

vector<int> anc;
vector<int> ch[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> name[i];
    sort(name + 1, name + n + 1);
    
    for(int i = 1; i <= n; i++) id[name[i]] = i;
    
    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        adj[id[y]].push_back(id[x]);
        deg[id[x]]++;
    }
    
    for(int i = 1; i <= n; i++){
        if (deg[i] == 0) anc.push_back(i);
    }
    
    cout << anc.size() << '\n';
    for (auto a : anc) cout << name[a] << ' ';
    cout << '\n';
    
    for(int i = 1; i <= n; i++){
        sort(adj[i].begin(), adj[i].end());
        for(int c : adj[i]){
            if (deg[c] - deg[i] == 1) ch[i].push_back(c);
        }
    }
    
    for(int i = 1; i <= n; i++){
        int sz = ch[i].size();
        cout << name[i] << ' ' << sz << ' ';
        for(int c : ch[i]) cout << name[c] << ' ';
        cout << '\n';
    }
    
}