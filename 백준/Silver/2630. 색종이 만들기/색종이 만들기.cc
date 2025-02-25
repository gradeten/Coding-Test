#include <bits/stdc++.h>
using namespace std;
int paper[130][130];
int answer[2];

bool same(int r,int c,int length){
    int firstValue = paper[r][c];
    for(int i = r; i < r+length; i++){
        for(int j = c; j < c+length; j++){
            if (firstValue != paper[i][j]){
                return false;
            }
        }
    }
    return true;
}
    
void func(int r, int c, int length){
    bool isSame = same(r, c, length);
    if (isSame){
        answer[paper[r][c]]++;
        return;
    }
    
    length /= 2;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            func(r+length*i, c+length*j, length);
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> paper[i][j];
        }
    }
    
    func(0, 0, n);
    cout << answer[0] << '\n' << answer[1] << '\n';
}