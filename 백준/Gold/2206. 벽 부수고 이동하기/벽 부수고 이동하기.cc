#include <bits/stdc++.h>
using namespace std;
char board[1002][1002];
int vis[1002][1002][2];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for (int j = 0; j < m; j++){
            board[i][j] = s[j];
        }
    }
    
    queue<tuple<int,int,int>> Q;
    vis[0][0][0] = 1;
    Q.push({0,0,0});
    
    while(!Q.empty()){
        auto [x,y,broken] = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            
            if (board[nx][ny] == '0' && vis[nx][ny][broken] == 0){
                vis[nx][ny][broken] = vis[x][y][broken]+1;
                Q.push({nx,ny,broken});
            }
            
            if (board[nx][ny] == '1' && broken == 0 && vis[nx][ny][1] == 0){
                vis[nx][ny][1] = vis[x][y][broken]+1;
                Q.push({nx,ny,1});
            }
        }
    }
    

    int no_break = vis[n-1][m-1][0];
    int break_wall = vis[n-1][m-1][1];
    
    if (no_break == 0 && break_wall == 0) cout << -1;
    else if (no_break == 0) cout << break_wall;
    else if (break_wall == 0) cout << no_break;
    else cout << min(no_break, break_wall);
}