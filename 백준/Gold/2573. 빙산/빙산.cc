#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int board[302][302];
int ice[302][302];

int bfs(void){
    queue<pair<int,int>> Q;
    int vis[302][302] = {0};
    int area = 0;
    
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (ice[i][j] != 0 && !vis[i][j]){
                area++;
                vis[i][j] = 1;
                Q.push({i,j});
                while (!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (vis[nx][ny] != 0 || ice[nx][ny] == 0) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
            }
        }
    }
    return area;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    
    int year = 0;

    while (true)
    {
        bool iceLeft = false;
        for(int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (board[i][j] != 0){
                    iceLeft = true;
                    int speed = 0;
                    for(int dir = 0; dir < 4; dir++){
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (board[nx][ny] == 0) speed++;
                    }
                    ice[i][j] = max(0,board[i][j] - speed);
                }
            }
        }
        if (!iceLeft){
            cout << 0;
            return 0;
        }
        
        
        year++;
        int a = bfs();
        if (a >= 2) break;
        
        for(int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                board[i][j] = ice[i][j];
        }
    }
    }
    
    cout << year;
    return 0;
    
}