#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int k = 0; k < places.size(); k++){
        char arr[10][10] = {0};
        bool vis[10][10] = {0};
        
        
        for(int i = 0; i < 5; i++){
            string s = places[k][i];
            for(int j = 0; j < 5; j++){
                arr[i][j] = s[j];
            }
        }
        
        queue<pair<int,int>> Q;
        bool flag = true;
        
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if (arr[i][j] == 'P'){
                    Q.push({i,j});
                    vis[i][j] = 1;
                    
                    while(!Q.empty()){
                        auto [x, y] = Q.front(); Q.pop();
                        for(int dir = 0; dir < 4; dir++){
                            int nx = x + dx[dir];
                            int ny = y + dy[dir];
                            int dist = abs(nx - i) + abs(ny - j);
                            
                            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                            if (vis[nx][ny] || dist > 2) continue;
                            
                            if (arr[nx][ny] == 'P') flag = false;
                            if (!flag) break;
                            
                            if (arr[nx][ny] == 'O'){
                                vis[nx][ny] = 1;
                                Q.push({nx,ny});
                            }
                        }
                    }
                }
            }
        }
        
        if (!flag) answer.push_back(0);
        else answer.push_back(1);
    }
    
    return answer;
}