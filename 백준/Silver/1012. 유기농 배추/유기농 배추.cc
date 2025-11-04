#include <bits/stdc++.h>
using namespace std;
int t, m, n, k, x, y;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--){   
        cin >> m >> n >> k;
        
        int arr[55][55] = {0};
        bool vis[55][55] = {0};
        
        while(k--){
            cin >> x >> y;
            arr[y][x] = 1;
        }
        
        int area = 0;
        queue<pair<int,int>> q;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if (arr[i][j] == 1 ){
                    if (vis[i][j]) continue;
                    area++;
                    vis[i][j] = 1;
                    q.push({i,j});
                    while(!q.empty()){
                        auto cur = q.front(); q.pop();
                        for(int dir = 0; dir < 4; dir++){
                            int ny = cur.first + dy[dir];
                            int nx = cur.second + dx[dir];
                            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                            if (vis[ny][nx] || arr[ny][nx] == 0) continue;
                            q.push({ny,nx});
                            vis[ny][nx] = 1;
                        }
                    }
                }
            }
        }
        
        cout << area << '\n';
    }
}