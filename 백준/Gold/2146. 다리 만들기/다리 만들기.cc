#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n;
int board[102][102] = {0};
int island[102][102] = {0};
int dist[102][102] = {0};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int label = 0;
int answer = 10000;

void label_island() {
    queue<pair<int, int>> Q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1 && island[i][j] == 0) {
                label++;
                island[i][j] = label;
                Q.push({i, j});
                while (!Q.empty()) {
                    auto cur = Q.front();
                    Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (board[nx][ny] == 0 || island[nx][ny] != 0) continue;
                        island[nx][ny] = label;
                        Q.push({nx, ny});
                    }
                }
            }
        }
    }
}

int distance() {
   for(int i = 0; i < n; i++) fill(dist[i], dist[i] + n, -1);
   queue<pair<int,int>> Q;
   
   for(int i = 0; i < n; i++){
       for (int j = 0; j < n; j++){
           if (island[i][j] != 0){
               Q.push({i,j});
               dist[i][j] = 0;
               bool escape = false;
               while(!Q.empty() && !escape){
                   auto cur = Q.front(); Q.pop();
                   for(int dir = 0; dir < 4; dir++){
                       int nx = cur.X + dx[dir];
                       int ny = cur.Y + dy[dir];
                       if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                       if (dist[nx][ny] >= 0 || island[i][j] == island[nx][ny]) continue;
                       if (island[nx][ny] != 0 && island[i][j] != island[nx][ny]){
                           answer = min(answer, dist[cur.X][cur.Y]);
                           while (!Q.empty()) Q.pop();
                           escape = true;
                           break;
                       }
                       dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                       Q.push({nx,ny});
                   }
               }
               for(int i = 0; i < n; i++) fill(dist[i], dist[i] + n, -1);
           }
       }
   }
   return answer;
}

int main(void) {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    label_island(); 
    cout << distance(); 

    return 0;
}
