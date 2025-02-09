#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool blind[101][101] = {false};
bool color[101][101] = {false};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    string board[N];
    for(int i = 0; i < N; i++) cin >> board[i];
    
    queue<pair<int,int> > Q;
    
    int area = 0;
    for (char c : {'R', 'G', 'B'}){
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (board[i][j] == c && !color[i][j]){
                    area++;
                    color[i][j] = 1;
                    Q.push({i,j});
                    while(!Q.empty()){
                        pair<int,int> cur = Q.front(); Q.pop();
                        for(int dir = 0; dir < 4; dir++){
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                            if (board[nx][ny] != c || color[nx][ny]) continue;
                            color[nx][ny] = 1;
                            Q.push({nx,ny});
                        }
                    }
                }
            }
        }
    }
    
    cout << area << " ";
    for(int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (board[i][j] == 'G') board[i][j] = 'R';
    
    area = 0;
    for (char c : {'R', 'B'}){
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (board[i][j] == c && !blind[i][j]){
                    area++;
                    blind[i][j] = 1;
                    Q.push({i,j});
                    while(!Q.empty()){
                        pair<int,int> cur = Q.front(); Q.pop();
                        for(int dir = 0; dir < 4; dir++){
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                            if (board[nx][ny] != c || blind[nx][ny]) continue;
                            blind[nx][ny] = 1;
                            Q.push({nx,ny});
                        }
                    }
                }
            }
        }
    }
    cout << area << " ";
    
}