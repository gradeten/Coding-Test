#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<string,int> &a, const pair<string,int> &b){
    return a.second > b.second;
}

bool cmp1(const pair<int,int> &a, const pair<int,int> &b){
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string,int> mp;
    unordered_map<string, vector<pair<int, int>>> mg;
    
    for(int i = 0; i < genres.size(); i++){
        mp[genres[i]] += plays[i];
        mg[genres[i]].push_back({plays[i],i});
    }
    
    vector<pair<string,int>> sg(mp.begin(), mp.end());
    sort(sg.begin(), sg.end(), cmp);
    
    for (auto &pair : sg){
        string genre = pair.first;
        auto &songs = mg[genre];
        
        sort(songs.begin(), songs.end(), cmp1);
        
        for(int i = 0; i < songs.size() && i < 2; i++){
            answer.push_back(songs[i].second);
        }
    }
    
    
    return answer;
}