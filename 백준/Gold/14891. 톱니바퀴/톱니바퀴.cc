#include <bits/stdc++.h>
using namespace std;

char wheel[4][8];
int answer = 0;

void clockwise(int n){
    int temp = wheel[n][7];
    for(int i = 7; i > 0; i--){
        wheel[n][i] = wheel[n][i-1];
    }
    wheel[n][0] = temp;
}

void reverse_clockwise(int n){
    int temp = wheel[n][0];
    for(int i = 0; i < 7; i++){
        wheel[n][i] = wheel[n][i+1];
    }
    wheel[n][7] = temp;
}

void get_score(){
    if (wheel[0][0] == '1') answer++;
    if (wheel[1][0] == '1') answer+=2;
    if (wheel[2][0] == '1') answer+=4;
    if (wheel[3][0] == '1') answer+=8;
}

int main (void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < 4; i++){
        string s;
        cin >> s;
        for(int j = 0; j < 8; j++){
            wheel[i][j] = s[j];
        }
    }
    
    int k;
    cin >> k;
    
    while(k--){
        int num, dir;
        cin >> num >> dir;
        num--;
        
        int rotate_dir[4] = {0};
        rotate_dir[num] = dir;
        
        for(int i = num; i > 0; i--){
            if(wheel[i][6] != wheel[i-1][2]){
                rotate_dir[i-1] = -rotate_dir[i];
            } else break;
        }
        
        for(int i = num; i < 3; i++){
            if (wheel[i][2] != wheel[i+1][6]){
                rotate_dir[i+1] = -rotate_dir[i];
            } else break;
        }
        
        for(int i = 0; i < 4; i++){
            if (rotate_dir[i] == 1) clockwise(i);
            else if (rotate_dir[i] == -1) reverse_clockwise(i);
        }
    }
    
    get_score();
    cout << answer;
    return 0;
}