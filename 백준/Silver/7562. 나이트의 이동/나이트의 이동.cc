#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int vis[301][301];
int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {2,1,-1,-2,-2,-1,1,2};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while(T--){
        queue<pair<int,int>> Q;
        
        int size;
        cin >> size;
        for(int i = 0; i < size; i++) fill(vis[i], vis[i]+size, 0);
        
        int startX, startY, endX, endY;
        cin >> startX >> startY >> endX >> endY;
        
        if (startX == endX && startY == endY){
            cout << 0 << "\n";
            continue;
        }
        
        Q.push({startX,startY});

        
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for(int dir = 0; dir < 8; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= size || ny < 0 || ny >= size) continue;
                if (vis[nx][ny] != 0) continue;
                vis[nx][ny] = vis[cur.X][cur.Y] + 1;
                if (nx == endX && ny == endY){
                    cout << vis[nx][ny] << "\n";
                    break;
                }
                Q.push({nx,ny});
            }
        }
        
        
        
    }
}