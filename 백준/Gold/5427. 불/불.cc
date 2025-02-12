#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
char board[1002][1002] = {0};
int fire[1002][1002] = {0};
int sang[1002][1002] = {0};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while(T--){
        int w, h;
        cin >> w >> h;
        
        int sangX, sangY;
        
        queue<pair<int,int>> Q1, Q2;
        
        for(int i = 0; i < h; i++){
            for (int j = 0; j < w; j++){
                board[i][j] = 0;
                fire[i][j] = -1;
                sang[i][j] = -1;
            }
        }
        
        for(int i = 0; i < h; i++){
            for (int j = 0; j < w; j++){
                cin >> board[i][j];
                if (board[i][j] == '*'){ fire[i][j] = 0; Q1.push({i,j});}
                if (board[i][j] == '@'){ sang[i][j] = 0; sangX = i; sangY = j;}
            }
        }
        
        if (sangX == 0 || sangY == 0 || sangX == h-1 || sangY == w-1){
            cout << 1 << "\n";
            continue;
        }
        
        while(!Q1.empty()){
            auto cur = Q1.front(); Q1.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (board[nx][ny] == '#' || fire[nx][ny] >= 0) continue;
                fire[nx][ny] = fire[cur.X][cur.Y] + 1;
                Q1.push({nx,ny});
            }
        }
        
        Q2.push({sangX, sangY});
        int answer = -1;
        
        while(!Q2.empty() && answer == -1){
            auto cur = Q2.front(); Q2.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (board[nx][ny] == '#' || sang[nx][ny] >= 0) continue;
                if (fire[nx][ny] != -1 && fire[nx][ny] <= sang[cur.X][cur.Y]+1) continue;
                sang[nx][ny] = sang[cur.X][cur.Y] + 1;
                if (nx == 0 || ny == 0 || nx == h-1 || ny == w-1){
                    answer = sang[nx][ny];
                    break;
                }
                Q2.push({nx,ny});
            }
        }
        
        if (answer == -1) cout << "IMPOSSIBLE\n";
        else cout << answer + 1 << "\n";
    }
}