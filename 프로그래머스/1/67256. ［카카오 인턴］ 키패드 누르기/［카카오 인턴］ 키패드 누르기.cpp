#include <bits/stdc++.h>
using namespace std;

pair<int,int> getPos (int num){
    if (num == 0) num = 11;
    int x = (num - 1) / 3;
    int y = (num - 1) % 3;
    return {x, y};
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int l = 10;
    int r = 12;
    
    for(int i = 0; i < numbers.size(); i++){
        int num = numbers[i];
        if (num == 0) num = 11;
        
        if (num % 3 == 1){
            answer += 'L';
            l = num;
        }
        else if (num % 3 == 0){
            answer += 'R';
            r = num;
        }
        else{
            auto [lx, ly] = getPos(l);
            auto [rx, ry] = getPos(r);
            auto [nx, ny] = getPos(num);
            
            int ldist = abs(lx - nx) + abs(ly - ny);
            int rdist = abs(rx - nx) + abs(ry - ny);
            
            if (ldist < rdist || (ldist == rdist && hand == "left")){
                answer += 'L';
                l = num;
            }
            else{
                answer += 'R';
                r = num;
            }
        }
        
    }
    
    return answer;
}