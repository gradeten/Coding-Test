#include <bits/stdc++.h>
using namespace std;
int n, m;
int room[50][50];
int r, c, d;
int answer = 0;

// 0: 북쪽, 1: 동쪽, 2: 남쪽, 3: 서쪽
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int startCleaning(int y, int x, int d){
    while(true){
        if (room[y][x] == 0){
            room[y][x] = 2;
            answer++;
        }
        
        bool cleaned = false;
        for(int i = 0; i < 4; i++){
            d = (d+3)%4;
            int ny = y + dy[d];
            int nx = x + dx[d];
            
            if (room[ny][nx] == 0){
                y = ny;
                x = nx;
                cleaned = true;
                break;
            }
        }
        
        if (cleaned) continue;
        
        int back = (d + 2) % 4;
        int by = y + dy[back];
        int bx = x + dx[back];
        
        if (room[by][bx] != 1){
            y = by;
            x = bx;
        }
        else break;
        
    }
    return answer;
}

int main (void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    cin >> r >> c >> d;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> room[i][j];
        }
    }
    
    cout << startCleaning(r,c,d);
}