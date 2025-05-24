#include <bits/stdc++.h>
using namespace std;
int n, m;
char board[50][50];
int answer = INT_MAX;

int main (void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    
    for(int i = 0; i <= n-8; i++){
        for(int j = 0; j <= m-8; j++){
            int repaint_w = 0;
            int repaint_b = 0;
            
            for(int r = i; r <= i+7; r++){
                for (int c = j; c <= j+7; c++){
                    if ((r+c) % 2 == 0){
                        if (board[r][c] != 'W') repaint_w++;
                        if (board[r][c] != 'B') repaint_b++;
                    }
                    else{
                        if (board[r][c] != 'B') repaint_w++;
                        if (board[r][c] != 'W') repaint_b++;
                    }
                }
            }
            
            answer = min(answer, min(repaint_w,repaint_b));
        }
    }
    
    cout << answer;
}