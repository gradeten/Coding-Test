#include <bits/stdc++.h>
using namespace std;
pair<int,int>board[4][4];
const int dx[8] = {-1,-1,0,1,1,1,0,-1};
const int dy[8] = {0,-1,-1,-1,0,1,1,1};
int ans = 0;

void moveFish(pair<int,int> b[4][4], int sx, int sy){
    for(int num = 1; num <= 16; num++){
        int x = -1, y = -1;
        // 1. 물고기 위치 찾기
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if (b[i][j].first == num){
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        
        if (x == -1) continue;
        
        int dir = b[x][y].second;
        
        for(int i = 0; i < 8; i++){
            int ndir = (dir+i) % 8;
            int nx = x + dx[ndir];
            int ny = y + dy[ndir];
            
            // 격자 밖 or 상어 위치면 스킵
            if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
            if (nx == sx && ny == sy) continue;
            
            // 이동 가능하면 자리 바꾸기
            swap(b[x][y], b[nx][ny]);
            b[nx][ny].second = ndir;
            break;
        }
    }
}

void dfs(pair<int,int> b[4][4], int sx, int sy, int sd, int total){
    // total: 지금까지 먹은 물고기의 합
    ans = max(ans, total);
    
    // 1. 물고기 이동
    moveFish(b, sx, sy);
    
    // 2. 상어 이동
    for(int step = 1; step <= 3; step++){
        int nx = sx + dx[sd] * step;
        int ny = sy + dy[sd] * step;
        if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
        if (b[nx][ny].first == 0) continue;
        
        // board 복사
        pair<int,int> newBoard[4][4];
        memcpy(newBoard, b, sizeof(newBoard));
        
        // 물고기 먹기
        int fishNum = newBoard[nx][ny].first;
        int fishDir = newBoard[nx][ny].second;
        newBoard[nx][ny].first = 0;
        
        dfs(newBoard, nx, ny, fishDir, total + fishNum);
    }
}

int main (void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            int num, dir;
            cin >> num >> dir;
            board[i][j] = {num, dir - 1};
        }
    }
    
    int firstFish = board[0][0].first;
    int firstDir = board[0][0].second;
    board[0][0].first = 0;
    
    dfs(board,0,0,firstDir, firstFish);
    
    cout << ans;
    
    
}