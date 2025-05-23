#include <bits/stdc++.h>
using namespace std;
int n,k,l;
int board[100][100] = {0};
vector<pair<int,char>> v;
queue<pair<int,int>> q;
int cur_d = 0;
int y, x;
int dy[4] = {0,1,0,-1}; // 우 하 좌 상
int dx[4] = {1,0,-1,0};
int sec = 0;

bool game(){
    
    sec++;

    int ny = y + dy[cur_d];
    int nx = x + dx[cur_d];
    
    if (ny < 0 || ny >= n || nx < 0 || nx >= n) return false;
    if (board[ny][nx] == 1) return false;
    if (board[ny][nx] == 2){
        board[ny][nx] = 1;
    }
    else{
        auto cur = q.front(); q.pop();
        board[cur.first][cur.second] = 0;
        board[ny][nx] = 1;
    }

    q.push({ny, nx});
    y = ny;
    x = nx;
    
        
    for(int i = 0; i < l; i++){
        if (sec == v[i].first){
            if (v[i].second == 'L') cur_d = (cur_d+3)%4;
            else if (v[i].second == 'D') cur_d = (cur_d+1)%4;
            break;
        }
    }
    
    return true;
}

int main (void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        int r,c;
        cin >> r >> c;
        board[r-1][c-1] = 2;
    }
    
    cin >> l;
    for(int i = 0; i < l; i++){
        int t; char d;
        cin >> t >> d;
        v.push_back({t,d});
    }
    
    board[0][0] = 1;
    q.push({0,0});
    y = 0; x = 0;
    
    while(true)
    {
        if (!game()) break;
    }
    
    cout << sec;
}