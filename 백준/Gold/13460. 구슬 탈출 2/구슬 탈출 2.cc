#include <bits/stdc++.h>
using namespace std;

int n, m;
char board[10][10];
int dy[4] = {-1,1,0,0}; // 상하좌우
int dx[4] = {0,0,-1,1};
int ry, rx, by, bx;

struct State{
    int ry, rx, by, bx, depth;
};

pair<int,int> move(int y, int x, int dy, int dx, int& cnt){
    cnt = 0;
    while(board[y+dy][x+dx] != '#' && board[y][x] != 'O'){
        y += dy;
        x += dx;
        cnt++;
        if (board[y][x] == 'O') break;
    }
    return {y,x};
}

int bfs(){
    queue<State> q;
    bool visited[10][10][10][10] = {false};
    
    q.push({ry,rx,by,bx,0});
    visited[ry][rx][by][bx] = true;
    
    while(!q.empty()){
        auto [rr, rc, br, bc, depth] = q.front(); q.pop();
        if (depth >= 10) return -1;
        
        for(int dir = 0; dir < 4; dir++){
            int rcnt = 0, bcnt = 0;
            auto [nrr, nrc] = move(rr, rc, dy[dir], dx[dir], rcnt);
            auto [nbr, nbc] = move(br, bc, dy[dir], dx[dir], bcnt);
            
            if (board[nbr][nbc] == 'O') continue; // 파란 구슬 빠지면 실패
            if (board[nrr][nrc] == 'O') return depth + 1; // 빨간 구슬 성공
            
            // 겹치는 경우
            if (nrr == nbr && nrc == nbc){
                if (rcnt > bcnt){
                    nrr -= dy[dir];
                    nrc -= dx[dir];
                }
                else{
                    nbr -= dy[dir];
                    nbc -= dx[dir];
                }
            }
            
            if (!visited[nrr][nrc][nbr][nbc]){
                visited[nrr][nrc][nbr][nbc] = true;
                q.push({nrr, nrc, nbr, nbc, depth + 1});
            }
        }
    }
    
    return -1;
}
 
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if (board[i][j] == 'R'){
                ry = i;
                rx = j;
            }
            if (board[i][j] == 'B'){
                by = i;
                bx = j;
            }
        }
    }
    
    cout << bfs();
}