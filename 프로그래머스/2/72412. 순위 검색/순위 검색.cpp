#include <bits/stdc++.h>
using namespace std;
map<string, vector<int>> keys;

void makeKeys(int idx, string key, vector<string>& data, int score){
    if (idx == 4){
        keys[key].push_back(score);
        return;
    }
    makeKeys(idx+1, key + data[idx], data, score);
    makeKeys(idx+1, key + "-", data, score);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for(int i = 0; i < info.size(); i++){
        string lang, job, level, food, score;
        istringstream iss(info[i]);
        iss >> lang >> job >> level >> food >> score;
        vector<string> data = {lang, job, level, food};
        makeKeys(0, "", data, stoi(score));
    }
    
    for(auto& k : keys){
        sort(k.second.begin(), k.second.end());
    }
    
    for(int i = 0; i < query.size(); i++){
        string lang, and1, job, and2, level, and3, food, score;
        istringstream iss(query[i]);
        iss >> lang >> and1 >> job >> and2 >> level >> and3 >> food >> score;
        
        string cond = lang + job + level + food;
        int sc = stoi(score);
        
        int ans = 0;
        if (keys.find(cond) != keys.end()){
            int idx = lower_bound(keys[cond].begin(), keys[cond].end(), sc) 
                - keys[cond].begin();
            ans = keys[cond].size() - idx;
        }
        
        answer.push_back(ans);
    }
    
    return answer;
}