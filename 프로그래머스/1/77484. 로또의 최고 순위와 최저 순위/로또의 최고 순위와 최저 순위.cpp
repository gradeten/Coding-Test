#include <bits/stdc++.h>
using namespace std;

int getRank(int cnt) {
    return cnt >= 2 ? 7 - cnt : 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> num(50,0);
    int right = 0, zero = 0;
    
    for(int w : win_nums) num[w]++;
    
    for(int l : lottos){
        if (l == 0) zero++;
        else if (num[l]) right++;
    }
    
    return { getRank(right + zero), getRank(right) };
}