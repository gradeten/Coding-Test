#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int by = brown+yellow;
    
    for(int i = 1; i*i <= by; i++){
        if (by % i == 0){
            if ((i-2)*(by/i-2) == yellow){
                answer.push_back(by/i);
                answer.push_back(i);
                break;
            }
        }
    }
    
    
    return answer;
}