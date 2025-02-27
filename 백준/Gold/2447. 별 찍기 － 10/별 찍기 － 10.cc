#include <bits/stdc++.h>
using namespace std;
char board[2200][2200];

void func(int r, int c, int l){
    if (l == 1){
        board[r][c] = '*';
        return;
    }
    
    l /= 3;
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (i == 1 && j == 1) continue;
            func(r + i * l, c + j * l, l);
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = ' ';
        }
    }
    
    func(0,0,n);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j];
        }
        cout << '\n';
    }
}