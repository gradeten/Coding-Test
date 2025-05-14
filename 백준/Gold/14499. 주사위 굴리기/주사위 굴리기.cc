#include <bits/stdc++.h>
using namespace std;
int n, m;
int board[20][20];
int dice[7] = {0,0,0,0,0,0,0};

bool in_range(int r, int c){
    return r >= 0 && r < n && c >= 0 && c < m;
}

void roll_east(){
    int temp = dice[1];
    dice[1] = dice[4];
    dice[4] = dice[6];
    dice[6] = dice[3];
    dice[3] = temp;
}

void roll_west(){
    int temp = dice[1];
    dice[1] = dice[3];
    dice[3] = dice[6];
    dice[6] = dice[4];
    dice[4] = temp;
}

void roll_north(){
    int temp = dice[1];
    dice[1] = dice[5];
    dice[5] = dice[6];
    dice[6] = dice[2];
    dice[2] = temp;
}

void roll_south(){
    int temp = dice[1];
    dice[1] = dice[2];
    dice[2] = dice[6];
    dice[6] = dice[5];
    dice[5] = temp;
}

int main (void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    int y, x, k;
    cin >> y >> x >> k;
    
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    
    
    while(k--){
        int dir;
        cin >> dir;
        int ny = y, nx = x;
        
        if (dir == 1){ // east
            nx++;  // x 좌표 증가
            if (!in_range(ny, nx)) continue;
            roll_east();
        }
        else if (dir == 2){ // west
            nx--;  // x 좌표 감소
            if (!in_range(ny, nx)) continue;
            roll_west();
        }
        else if (dir == 3){ // north
            ny--;  // y 좌표 감소
            if (!in_range(ny, nx)) continue;
            roll_north();
        }
        else if (dir == 4){ // south
            ny++;  // y 좌표 증가
            if (!in_range(ny, nx)) continue;
            roll_south();
        }
        
        // 이동 후 좌표 갱신
        y = ny;
        x = nx;
        
        // 지도 값 처리
        if (board[ny][nx] == 0) {
            board[ny][nx] = dice[6];
        } else {
            dice[6] = board[ny][nx];
            board[ny][nx] = 0;
        }
        
        cout << dice[1] << "\n";
    }
}