#include <bits/stdc++.h>
using namespace std;
int n;
int inning[50][9];
vector<int> l;
int answer = 0;


// 2. n 번째 이닝이 끝날 때까지 경기 진행, 점수 기록
// 3. 기존 최대 점수와의 비교를 통해 최대 점수를 기록
void score(){
    int in = 0;
    int idx = 0;
    int sum = 0;

    while (in < n) {
        int out = 0;
        int base[3] = {0}; // 1루, 2루, 3루

        while (out < 3) {
            int cur = inning[in][l[idx]];
            idx = (idx + 1) % 9;

            if (cur == 0) {
                out++;
            }
            else if (cur == 1) {
                sum += base[2];
                base[2] = base[1];
                base[1] = base[0];
                base[0] = 1;
            }
            else if (cur == 2) {
                sum += base[2] + base[1];
                base[2] = base[0];
                base[1] = 1;
                base[0] = 0;
            }
            else if (cur == 3) {
                sum += base[2] + base[1] + base[0];
                base[2] = 1;
                base[1] = 0;
                base[0] = 0;
            }
            else if (cur == 4) {
                sum += base[2] + base[1] + base[0] + 1;
                base[2] = base[1] = base[0] = 0;
            }
        }
        in++;
    }
    answer = max(answer, sum);
}

// 1. 타자 순서 정하기 (1번 선수는 4번으로 고정)
void get_list(){
    vector<int> players;
    for (int i = 1; i <= 8; i++) players.push_back(i); // 0번 제외

    do {
        l.clear();
        for (int i = 0; i < 3; i++) l.push_back(players[i]);
        l.push_back(0); // 4번째에 0번 타자 고정
        for (int i = 3; i < 8; i++) l.push_back(players[i]);
        score();
    } while (next_permutation(players.begin(), players.end()));
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 9; j++){
            cin >> inning[i][j];
        }
    }
    
    get_list();
    cout << answer;
}