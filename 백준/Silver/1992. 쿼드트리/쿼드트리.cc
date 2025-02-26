#include <bits/stdc++.h>
using namespace std;
char screen[66][66];

bool same(int r, int c, int l){
    int firstValue = screen[r][c];
    
    for(int i = r; i < r + l; i++){
        for (int j = c; j < c + l; j++){
            if (firstValue != screen[i][j]){
                return false;
            }
        }
    }
    return true;
}

void func(int r, int c, int l){
    bool isSame = same(r,c,l);
    if (isSame){
        cout << screen[r][c];
        return;
    }
    l /= 2;
    cout << '(';
    for(int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            func(r+i*l, c+j*l, l);
        }
    }
    cout << ')';
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for (int j = 0; j < n; j++){
            screen[i][j] = s[j];
        }
    }
    
    func(0,0,n);
}