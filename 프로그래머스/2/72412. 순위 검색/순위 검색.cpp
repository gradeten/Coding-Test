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
        string s = info[i];
        stringstream ss(s);
        string word;
        vector<string> words;
        
        while(getline(ss, word, ' ')){
            words.push_back(word);
        }
        
        vector<string> data = {words[0], words[1], words[2], words[3]};
        int score = stoi(words[4]);
        
        makeKeys(0,"", data, score);
    }
    
    for(auto& p : m){
        sort(p.second.begin(), p.second.end());
    }
    
    for(int i = 0; i < query.size(); i++){
        string s = query[i];
        stringstream ss(s);
        string word;
        vector<string> words;
        string key = "";
        
        while(getline(ss, word, ' ')){
            words.push_back(word);
        }
        
        for(int i = 0; i <= 6; i+=2){
            key += words[i];
        }
        int num_cond = stoi(words[7]);
        
        int result = 0;
        if (m.find(key) != m.end()){
            int idx = lower_bound(m[key].begin(), m[key].end(), num_cond) - m[key].begin();
            result = m[key].size() - idx;
        }
        
        answer.push_back(result);
    }
    
    
    return answer;
}