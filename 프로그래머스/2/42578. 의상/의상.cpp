#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map <string, int> m;
    for(int i = 0; i < clothes.size(); i++){
        string s = clothes[i][1];
        if (m.find(s) != m.end()){
            m[s]++;
        }
        else{
            m.insert({s,1});
        }
    }
    
    for(auto p : m) {
        int i = (p.second+1);
        answer *= i;
    }
    
    return answer-1;
}