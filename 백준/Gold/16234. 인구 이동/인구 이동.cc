#include <bits/stdc++.h>
using namespace std;
int n, l, r;
int board[50][50];
bool vis[50][50];
int answer = 0;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};

bool check_land(){
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            vis[i][j] = false;
        }
    }
    bool moved = false;
    
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            
            if (vis[i][j]) continue;
            
            vector<pair<int,int>> uni;
            queue<pair<int,int>> q;
            
            q.push({i,j});
            vis[i][j] = true;
            uni.push_back({i,j});
            
            int sum = board[i][j];
            
            while(!q.empty()){
                auto [y,x] = q.front(); q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int ny = y + dy[dir];
                    int nx = x + dx[dir];
                    if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                    if (vis[ny][nx]) continue;
                    int diff = abs(board[ny][nx] - board[y][x]);
                    if (diff < l || diff > r) continue;
                    
                    vis[ny][nx] = true;
                    q.push({ny,nx});
                    uni.push_back({ny,nx});
                    sum += board[ny][nx];
                }
            }
            
            if (uni.size() > 1){
                moved = true;
                int new_pop = sum / uni.size();
                for (auto [y,x] : uni){
                    board[y][x] = new_pop;
                }
            }
        }
        
    }
    
    return moved;
}

int main (void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> l >> r;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
    
    while(true){
        if (!check_land()) break;
        answer++;
    }
    cout << answer;
}