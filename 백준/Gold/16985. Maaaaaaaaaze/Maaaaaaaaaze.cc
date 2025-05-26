#include <bits/stdc++.h>
using namespace std;

int board[5][5][5]; // 입력 원본
int rotated[5][4][5][5]; // [층][회전][행][열]
int dz[6] = {1,-1,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dx[6] = {0,0,0,0,1,-1};
int answer = INT_MAX;

void rotate90(int src[5][5], int dest[5][5]){
    for (int y = 0; y < 5; y++)
        for (int x = 0; x < 5; x++)
            dest[x][4-y] = src[y][x];
}

bool isValid(int z, int y, int x){
    return (0 <= z && z < 5 && 0 <= y && y < 5 && 0 <= x && x < 5);
}

int bfs(int maze[5][5][5]){
    if (maze[0][0][0] == 0 || maze[4][4][4] == 0) return -1;
    
    queue<tuple<int,int,int,int>> q;
    bool visited[5][5][5] = {};
    visited[0][0][0]= true;
    q.push({0,0,0,0}); // z, y, x, dist
    
    while(!q.empty()){
        auto [z,y,x,dist] = q.front(); q.pop();
        if (z == 4 && y == 4 && x == 4) return dist;
        
        for(int dir = 0; dir < 6; dir++){
            int nz = z + dz[dir];
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (!isValid(nz,ny,nx)) continue;
            if (visited[nz][ny][nx]) continue;
            if (maze[nz][ny][nx] == 0) continue;
            
            visited[nz][ny][nx] = true;
            q.push({nz,ny,nx,dist+1});
        }
    }
    return -1;
}

void buildAndCheck(vector<int> &order, vector<int> &rot){
    int maze[5][5][5];
    
    // 구성하기
    for (int z = 0; z < 5; z++){
        int layer = order[z];
        int r = rot[z];
        for(int y = 0; y < 5; y++)
            for (int x = 0; x < 5; x++)
                maze[z][y][x] = rotated[layer][r][y][x];
    }
    
    // BFS로 최단 거리 확인
    int res = bfs(maze);
    if (res != -1)
        answer = min(answer, res);
}

void tryAllCases(){
    vector<int> order = {0,1,2,3,4};
    vector<int> rot(5);
    
    do{
        // 4^5 회전 조합
        for(int a = 0; a < 4; a++)
            for(int b = 0; b < 4; b++)   
                for(int c = 0; c < 4; c++)
                    for(int d = 0; d < 4; d++)
                        for(int e = 0; e < 4; e++){
                            rot = {a,b,c,d,e};
                            buildAndCheck(order,rot);
                        }
    } while (next_permutation(order.begin(), order.end()));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 입력
    for(int z = 0; z < 5; z++)
        for(int y = 0; y < 5; y++)
            for (int x = 0; x < 5; x++)
                cin >> board[z][y][x];
    
    // 각 층 회전 미리 구하기
    for (int z = 0; z < 5; z++){
        memcpy(rotated[z][0], board[z],sizeof(board[z]));
        for (int r = 1; r < 4; r++)
            rotate90(rotated[z][r-1], rotated[z][r]);
    }
    
    // 모든 조합 시도
    tryAllCases();
    
    // 결과 출력
    if (answer == INT_MAX) cout << -1;
    else cout << answer;
    
    return 0;
}