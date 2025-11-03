#include <bits/stdc++.h>
using namespace std;

map<string, vector<int>> m;

void makeKeys(int idx, string key, vector<string>& data, int score){
    if (idx == 4){
        m[key].push_back(score);
        return;
    }
    makeKeys(idx+1, key + data[idx], data, score);
    makeKeys(idx+1, key + "-", data, score);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for(int i = 0; i < info.size(); i++){
        string lang, job, career, food;
        int score;
        istringstream iss(info[i]);
        iss >> lang >> job >> career >> food >> score;
        
        vector<string> data = {lang, job, career, food};
        makeKeys(0,"", data, score);
    }
    
    for(auto& p : m){
        sort(p.second.begin(), p.second.end());
    }
    
    for(int i = 0; i < query.size(); i++){
        string lang, and1, job, and2, career, and3, food;
        int num_cond;
        istringstream iss(query[i]);
        iss >> lang >> and1 >> job >> and2 >> career >> and3 >> food >> num_cond;
        
        string key = lang + job + career + food;
        
        int result = 0;
        if (m.find(key) != m.end()){
            int idx = lower_bound(m[key].begin(), m[key].end(), num_cond) - m[key].begin();
            result = m[key].size() - idx;
        }
        
        answer.push_back(result);
    }
    
    
    return answer;
}