#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while(T--){
        int board[50][50] = {0};
        bool worm[50][50] = {0};
        
        int M, N, K;
        cin >> M >> N >> K;
        
        queue<pair <int, int> > Q;
        int area = 0;
        
        while(K--){
            int a, b;
            cin >> a >> b;
            board[a][b] = 1;
        }
        
        for(int i = 0; i < M; i++){
            for (int j = 0; j < N; j++){
                if (!worm[i][j] && board[i][j] == 1){
                    area++;
                    worm[i][j] = 1;
                    Q.push({i,j});
                    while (!Q.empty()){
                        pair<int, int> cur = Q.front(); Q.pop();
                        for(int dir = 0; dir < 4; dir++){
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
                            if (worm[nx][ny] || board[nx][ny] != 1) continue;
                            worm[nx][ny] = 1;
                            Q.push({nx,ny});
                        }
                    }
                }
            }
        }
        cout << area << "\n";
    }
}