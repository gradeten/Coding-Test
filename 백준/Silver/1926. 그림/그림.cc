#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[502][502];
bool vis[502][502];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n, m;

int main (void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num = 0;
    int max = 0;
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (!vis[i][j] && board[i][j] == 1){
                num++;
                int area = 0;
                vis[i][j] = 1;
                queue<pair<int,int> > Q;
                Q.push({i,j});
                while(!Q.empty()){
                    area++;
                    pair<int,int> cur = Q.front(); Q.pop();
                    // cout << '(' << cur.X << ", " << cur.Y << ") -> ";
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (vis[nx][ny] || board[nx][ny] != 1) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
                if (area > max) max = area;
            }
        }
    }
    cout << num << "\n" << max;
    
}