#include <bits/stdc++.h>
using namespace std;
int n, m;
int board[8][8];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int answer = -1;

int bfs(int tmp[8][8]){
    queue<pair<int,int>> q;
    
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (tmp[i][j] == 2){
                q.push({i,j});
                
                while(!q.empty()){
                    auto [y,x] = q.front(); q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int ny = y + dy[dir];
                        int nx = x + dx[dir];
                        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                        if (tmp[ny][nx] == 1 || tmp[ny][nx] == 2) continue;
                        tmp[ny][nx] = 2;
                        q.push({ny,nx});
                    }
                }
            }
        }
    }
    
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (tmp[i][j] == 0){
                cnt++;
            }
        }
    }
    return cnt;
}

void dfs(int wallCount, int start){
    if (wallCount == 3){
        int tmp[8][8];
        memcpy(tmp, board, sizeof(board));
        answer = max(answer,bfs(tmp));
        return;
    }
    for(int i = start; i < n * m; i++){
        int y = i / m;
        int x = i % m;
        
        if (board[y][x] == 0){
            board[y][x] = 1;
            dfs(wallCount+1, i + 1);
            board[y][x] = 0;
        }
    }
}

int main (void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    
    dfs(0,0);
    cout << answer;
}