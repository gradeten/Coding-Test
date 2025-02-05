#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int tomato[1002][1002];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    queue<pair<int,int> > Q;
    
    int day = 0;
    int tot_tomatoes = 0;
    int tomatoes = 0;
    int m, n;
    cin >> m >> n;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int a;
            cin >> a;
            if (a == 1 || a == 0) tot_tomatoes++;
            if (a == 1){
                Q.push({i,j});
                tomatoes++;
            }
            tomato[i][j] = a;
        }
    }
    
    if (tomatoes == tot_tomatoes){
        cout << 0;
        return 0;
    }

    while(!Q.empty()){
        int size = Q.size();
        bool ripened = false;
        
        for(int i = 0; i < size; i++)
        {
            pair<int,int> cur = Q.front(); Q.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (tomato[nx][ny] == 1 || tomato[nx][ny] == -1) continue;
                
                tomato[nx][ny] = 1;
                tomatoes++;
                Q.push({nx,ny});
                ripened = true;
            }
        }
        
        if(ripened) day++;
    }
   
    if(tomatoes == tot_tomatoes) cout << day;
    else cout << -1;
    
    
}