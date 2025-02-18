#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[202][202];
int vis[202][202][31];
int mx[4] = {1,0,-1,0};
int my[4] = {0,1,0,-1};
int hx[8] = {1,2,1,2,-1,-2,-1,-2};
int hy[8] = {2,1,-2,-1,2,1,-2,-1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k, w, h;
    cin >> k >> w >> h;
    
    for(int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            cin >> board[i][j];
        }
    }
    
    memset(vis, -1, sizeof(vis));
    
    queue<tuple<int,int,int>> Q;
    vis[0][0][k] = 0;
    Q.push({0,0,k});
    
    while(!Q.empty()){
        auto [curX, curY, remain] = Q.front(); Q.pop();
        
        if(curX == h-1 && curY == w-1) {
            cout << vis[curX][curY][remain];
            return 0;
        }
        
        if (remain > 0) {
            for (int dir = 0; dir < 8; dir++) {
                int nx = curX + hx[dir];
                int ny = curY + hy[dir];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (board[nx][ny] == 1 || vis[nx][ny][remain-1] != -1) continue;
                vis[nx][ny][remain-1] = vis[curX][curY][remain] + 1;
                Q.push({nx, ny, remain-1});
            }
        }
        
        for(int dir = 0; dir < 4; dir++){
            int nx = curX + mx[dir];
            int ny = curY + my[dir];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (board[nx][ny] == 1 || vis[nx][ny][remain] != -1) continue;
            vis[nx][ny][remain] = vis[curX][curY][remain] + 1;
            Q.push({nx,ny, remain});
        }

    }
    
    
    cout << -1;
    return 0;
}