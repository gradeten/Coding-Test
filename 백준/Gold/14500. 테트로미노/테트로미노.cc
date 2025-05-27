#include <bits/stdc++.h>
using namespace std;
int board[500][500];
bool vis[500][500];
int n, m;
int answer = 0;
int dy[4] = {0,0,-1,1};
int dx[4] = {1,-1,0,0};

void dfs(int y, int x, int depth, int sum){
    if (depth == 4){
        answer = max(answer,sum);
        return;
    }
    
    for(int dir = 0; dir < 4; dir++){
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (vis[ny][nx]) continue;
        
        vis[ny][nx] = true;
        dfs(ny,nx,depth+1,sum+board[ny][nx]);
        vis[ny][nx] = false;
    }
}

void check_special(int y, int x){
    int center = board[y][x];
    for(int i = 0; i < 4; i++){
        int tmp = center;
        bool valid = true;
        for(int j = 0; j < 3; j++){
            int dir = (i + j) % 4;
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m){
                valid = false;
                break;
            }
            tmp += board[ny][nx];
        }
        if (valid) answer = max(answer,tmp);
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            vis[i][j] = true;
            dfs(i,j,1,board[i][j]);
            vis[i][j] = false;
            check_special(i,j);
        }
    }
    
    cout << answer;
}