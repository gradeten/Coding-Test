#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    vector<pair<string,string>> p;
    map<string,int> m;
    sort(report.begin(), report.end());
    
    for(int i = 0; i < report.size(); i++){
        if (i != report.size() -1){
            if (report[i] == report[i+1]) continue;
        }
        string word1, word2;
        istringstream iss(report[i]);
        iss >> word1 >> word2;
        
        p.push_back({word1,word2});
        m[word2]++;
    }
    
    for(auto i : id_list){
        int num = 0;
        for(auto pp: p){
            if (pp.first == i){
                if (m[pp.second] >= k)  num++;
            }
        }
        answer.push_back(num);
    }
    
    return answer;
}