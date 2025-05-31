#include <bits/stdc++.h>
using namespace std;

int N, M, H;
int ladder[31][31];
int answer = 4;

bool simulate(){
    for(int i = 1; i <= N; i++){
        int pos = i;
        for(int row = 1; row <= H; row++){
            if (ladder[row][pos]) pos++;
            else if (ladder[row][pos-1]) pos--;
        }
        if (pos != i) return false;
    }
    return true;
}

void dfs(int depth, int x, int y){
    if (depth >= answer) return;
    if (simulate()){
        answer = depth;
        return;
    }
    if (depth == 3) return;
    
    for(int i = x; i <= H; i++){
        for(int j = 1; j < N; j++){
            if (ladder[i][j] || ladder[i][j-1] || ladder[i][j-1]) continue;
            ladder[i][j] = 1;
            dfs(depth + 1, i, j);
            ladder[i][j] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> H;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        ladder[a][b] = 1;
    }
    dfs(0,1,1);
    if (answer > 3) cout << -1;
    else cout << answer;
}