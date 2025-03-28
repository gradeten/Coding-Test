#include <bits/stdc++.h>
using namespace std;
int dz[6] = {0,0,0,0,1,-1};
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};


int main(void){
    int M, N, H;
    cin >> M >> N >> H;
    
    int board[H][N][M];
    int tomato[H][N][M];
    memset(tomato, 0, sizeof(tomato));

    
    
    queue <tuple <int, int, int>> Q;
    
    for (int i = 0; i < H; i++){
        for (int j = 0; j < N; j++){
            for (int k = 0; k < M; k++){
                cin >> board[i][j][k];
                if (board[i][j][k] == 1) Q.push({i,j,k});
                if (board[i][j][k] == 0) tomato[i][j][k] = -1;
            }
        }
    }
    
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 6; dir++){
            int nz = get<0>(cur) + dz[dir];
            int nx = get<1>(cur) + dx[dir];
            int ny = get<2>(cur) + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H) continue;
            if (board[nz][nx][ny] == -1 || tomato[nz][nx][ny] >= 0) continue;
            tomato[nz][nx][ny] = tomato[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            Q.push({nz,nx,ny});
        }
    }
    
    int answer = 0;
    for (int i = 0; i < H; i++){
        for (int j = 0; j < N; j++){
            for (int k = 0; k < M; k++){
                if (tomato[i][j][k] == -1){
                    cout << -1;
                    return 0;
                }
                answer = max(answer, tomato[i][j][k]);
            }
        }
    }
    cout << answer;
    
    
}