#include <bits/stdc++.h>
using namespace std;

int n, k, l;
int board[101][101];
map<int,char> turn;
int dx[4] = {1, 0, -1, 0}; // 동, 남, 서, 북
int dy[4] = {0, 1, 0, -1}; 

int main (void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    while(k--){
        int y, x;
        cin >> y >> x;
        board[y-1][x-1] = 1;
    }
    
    cin >> l;
    while(l--){
        int t; char c;
        cin >> t >> c;
        turn[t] = c;
    }
    
    deque<pair<int,int>> snake;
    snake.push_back({0,0});
    board[0][0] = 2;
    
    int time = 0;
    int dir = 0;
    
    while(true){
        time++;
        int ny = snake.front().first + dy[dir];
        int nx = snake.front().second + dx[dir];
        
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || board[ny][nx] == 2) break;
        if (board[ny][nx] == 1){
            board[ny][nx] = 2;
            snake.push_front({ny,nx});
        }
        else{
            board[ny][nx] = 2;
            snake.push_front({ny,nx});
            auto tail = snake.back();
            board[tail.first][tail.second] = 0;
            snake.pop_back();
        }
        if (turn.count(time)){
            if (turn[time] == 'L') dir = (dir+3) % 4;
            else dir = (dir+1) % 4;
        }
    }
    
    cout << time;
}