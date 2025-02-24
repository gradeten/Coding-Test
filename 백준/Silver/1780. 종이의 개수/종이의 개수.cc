#include <bits/stdc++.h>
using namespace std;
int answer[3] = {0};
int paper[2200][2200] = {0};

bool same(int r, int c, int length){
    int firstValue = paper[r][c];
    for(int i = r; i < r+length; i++){
        for (int j = c; j < c+length; j++){
            if (firstValue != paper[i][j]) return false;
        }
    }
    return true;
}

void func(int r, int c, int length){
    int isSame = same(r, c, length);
    if (isSame){
        answer[paper[r][c]+1]++;
        return;
    }
    
    length /= 3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            func(r+i*length, c+j*length, length);
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> paper[i][j];
        }
    }
    
    func(0, 0, n);
    for(int i = 0; i < 3; i++) cout << answer[i] << '\n';
    
}