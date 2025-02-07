#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
char board[1001][1001];
int fire[1001][1001];
int jihoon[1001][1001];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int r, c;
    cin >> r >> c;
    
    for(int i = 0; i < r; i++){
         for (int j = 0; j < c; j++){
              fire[i][j] = -1;
              jihoon[i][j] = -1;
         }
    }
    
    queue<pair<int,int> > Q;
    int a, b;
    
    for(int i = 0; i < r; i++){
         for (int j = 0; j < c; j++){
              cin >> board[i][j];
              if (board[i][j] == 'F') {fire[i][j] = 0; Q.push({i,j});}
              else if (board[i][j] == 'J') {jihoon[i][j] = 0; a = i; b = j;}
         }
    }
    

    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (board[nx][ny] == '#' || fire[nx][ny] >= 0) continue;
            fire[nx][ny] = fire[cur.X][cur.Y] + 1;
            Q.push({nx,ny});
        }
    }
    
    Q.push({a,b});
    
    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c){
                cout << jihoon[cur.X][cur.Y] + 1;
                return 0;
            }
            if (board[nx][ny] == '#' || jihoon[nx][ny] >= 0) continue;
            if (fire[nx][ny] != -1 && fire[nx][ny] <= jihoon[cur.X][cur.Y]+1) continue;
            jihoon[nx][ny] = jihoon[cur.X][cur.Y] + 1;
            Q.push({nx,ny});
        }
    }


    cout << "IMPOSSIBLE";
    
}
