#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> freq;
int n, m, k;
char arr[15][15];
int dx[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, 1, -1};

void dfs(int x, int y, string cur, int depth){
    freq[cur]++;
    if (depth == 5) return;
    
    for(int dir = 0; dir < 8; dir++){
        int nx = (x + dx[dir] + n) % n;
        int ny = (y + dy[dir] + m) % m;
        dfs(nx, ny, cur + arr[nx][ny], depth + 1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            string start(1, arr[i][j]);
            dfs(i, j, start, 1);
        }
    }
    
    while(k--){
        string s; cin >> s;
        cout << freq[s] << '\n';
    }
}