#include <bits/stdc++.h>
using namespace std;

char board[12][6];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

bool in_range(int r, int c){
    return r >= 0 && r < 12 && c >= 0 && c < 6;
}

void gravity(){
    for(int j = 0; j < 6; j++){
        queue<char> q;
        for(int i = 11; i >= 0; i--){
            if (board[i][j] != '.'){
                q.push(board[i][j]);
                board[i][j] = '.';
            }
        }
        
        int idx = 11;
        while (!q.empty()){
            board[idx--][j] = q.front(); q.pop();
        }
    }
}

bool boom(){
    bool vis[12][12] = {false};
    bool isBoomed = false;
    
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 6; j++){
            if (board[i][j] == '.' || vis[i][j]) continue;

            char color = board[i][j];
            vector<pair<int,int>> v;
            queue<pair<int,int>> q;
            
            v.push_back({i,j});
            q.push({i,j});
            vis[i][j] = true;
            
            while(!q.empty()){
                auto [y,x] = q.front(); q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int ny = y + dy[dir];
                    int nx = x + dx[dir];
                    if (!in_range(ny,nx)) continue;
                    if (vis[ny][nx]) continue;
                    if (board[ny][nx] != color) continue;
                    vis[ny][nx] = true;
                    q.push({ny,nx});
                    v.push_back({ny,nx});
                }
            }
            
            if (v.size() >= 4){
                isBoomed = true;
                for (auto [y,x] : v){
                    board[y][x] = '.';
                }
            }
        }
    }
    return isBoomed;
    
    
}

int main (void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < 12; i++){
        string s; cin >> s;
        for(int j = 0; j < 6; j++){
            board[i][j] = s[j];
        }
    }
    
    int answer = 0;
    while(true){
        if (!boom()) break;
        gravity();
        answer++;
    }
    
    cout << answer;
    return 0;
}