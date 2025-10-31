#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> s;
    
    s.insert(words[0]);
    
    for(int i = 1; i < words.size(); i++){
        if (s.find(words[i]) != s.end() || 
            words[i][0] != words[i-1][words[i-1].size()-1]){
            if ((i+1) % n == 0){
                return {n, (i+1) / n};
            }
            else{
                return {(i+1) % n, (i+1) / n + 1};
            };
        }
        else{
            s.insert(words[i]);
        }
    }

    return {0,0};
}