#include <bits/stdc++.h>
using namespace std;

int board[101][101];
int dx[4] = {1,0,-1,0}; // 동, 북, 서, 남
int dy[4] = {0,-1,0,1};

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    while(n--){
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        
        vector<int> dir;
        dir.push_back(d);
        
        for(int gen = 0; gen < g; gen++){
            int size = dir.size();
            for(int i = size - 1; i >= 0; i--){
                dir.push_back((dir[i] + 1) % 4);
            }
        }
        
        board[y][x] = true;
        for(int i = 0; i < dir.size(); i++){
            x += dx[dir[i]];
            y += dy[dir[i]];
            board[y][x] = true;
        }
    }
    
    int answer = 0;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if (board[i][j] && board[i][j+1] && board[i+1][j] && board[i+1][j+1]){
                answer++;
            }
        }
    }
    
    cout << answer;
    return 0;
}