#include <bits/stdc++.h>
using namespace std;
int n;
int s[21][21];
int min_score = 999999;
vector<int> teamA;

void make_team(int idx, int cnt){
    if (cnt == n / 2){
        vector<int> teamB;
        for(int i = 0; i < n; i++){
            if (find(teamA.begin(), teamA.end(), i) == teamA.end())
                teamB.push_back(i);
        }
        int scoreA = 0;
        int scoreB = 0;
        
        for(int i = 0; i < teamA.size(); i++){
            for(int j = i + 1; j < teamA.size(); j++){
                int x = teamA[i]; int y = teamA[j];
                scoreA += s[x][y] + s[y][x];
            }
        }
        
        for(int i = 0; i < teamB.size(); i++){
            for(int j = i + 1; j < teamB.size(); j++){
                int x = teamB[i]; int y = teamB[j];
                scoreB += s[x][y] + s[y][x];
            }
        }
        
        min_score = min(min_score, abs(scoreA - scoreB));
        return;
    }
    
    for(int i = idx; i < n; i++){
        teamA.push_back(i);
        make_team(i + 1, cnt + 1);
        teamA.pop_back();
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> s[i][j];
        }
    }
    
    make_team(0,0);
    cout << min_score;
    
}