#include <bits/stdc++.h>
using namespace std;
char board[3100][6200];

void func(int r, int c, int l){
    if (l == 3){
        board[r][c+2] = '*';
        board[r+1][c+1] = '*';
        board[r+1][c+3] = '*';
        for(int j = 0; j < 5; j++) board[r+2][c+j] = '*';
        return;
    }
    
    l /= 2;
    func(r, c+l, l);
    func(r+l, c, l);
    func(r+l, c + 2*l, l);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for (int j = 0; j < 2*n; j++){
            board[i][j] = ' ';
        }
    }
    
    func(0,0,n);
    
    for(int i = 0; i < n; i++){
        for (int j = 0; j < 2*n; j++){
            cout << board[i][j];
        }
        cout << '\n';
    }
}