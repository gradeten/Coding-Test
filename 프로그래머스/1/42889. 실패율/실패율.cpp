#include <string>
#include <vector>
#include <map>
#include <bits/stdc++.h> 
#include <algorithm>

using namespace std;

bool cmp(const pair<int, double> &a, const pair<int, double> &b) 
{ 
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second; 
} 

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    map<int, double> mapset;
    
    for(int i = 1; i <=N; i++){
        int fail = 0;
        int user = stages.size();
        
        for(int j = 0; j < stages.size(); j++){
            if (stages[j] == i){
                fail++;
            }
            if (stages[j] < i)
            {
                user--;
            }
        }
        if(user == 0)
        {
            mapset[i] = 0;
        }
        else
        {
        mapset[i] = (double)fail/(double)user;
        }
    }
    
    vector<pair<int, double>> mapPairs(mapset.begin(), mapset.end());
    sort(mapPairs.begin(), mapPairs.end(), cmp);
    
    for (const pair<int, double> &pair : mapPairs) {
        answer.push_back(pair.first);
    }
    
    
    return answer;
}