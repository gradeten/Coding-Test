#include <bits/stdc++.h>
using namespace std;
int n, l;
int board[100][100];

// 경사로 설치 가능한지 체크
bool check(vector<int>& line){
    int size = line.size();
    vector<bool> used(size,false); // 경사로 설치 여부 체크

    for(int i = 0; i < size - 1; i++){
        int diff = line[i+1] - line[i];
        
        if (diff == 0) continue; // 높이 같음
        
        if(abs(diff) > 1) return false; // 경사로 설치 불가
        
        // 올라가는 경사로
        if (diff == 1){
            for(int j = i; j > i - l; j--){
                if (j < 0 || line[j] != line[i] || used[j]) return false;
                used[j] = true;
            }
        }
        
        // 내려가는 경사로
        else if (diff == -1){
            for(int j = i + 1; j <= i + l; j++){
                if (j >= size || line[j] != line[i+1] || used[j]) return false;
                used[j] = true;
            }
        }    
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> l;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
    
    int ans = 0;
    
    // 가로줄 체크
    for(int i = 0; i < n; i++){
        vector<int> row;
        for(int j = 0; j < n; j++){
            row.push_back(board[i][j]);
        }
        if(check(row)) ans++;
    }
    
    // 세로줄 체크
    for(int j = 0; j < n; j++){
        vector<int> col;
        for(int i = 0; i < n; i++){
            col.push_back(board[i][j]);
        }
        if(check(col)) ans++;
    }
    
    cout << ans;
}