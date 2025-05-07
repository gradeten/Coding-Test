#include <bits/stdc++.h>
using namespace std;

vector<string> answer;
bool finished = false;

void dfs(string curr, vector<vector<string>>& tickets, vector<bool>& visited, vector<string>& path, int depth){
    path.push_back(curr);
    
    if (depth == tickets.size()){
        answer = path;
        finished = true;
        return;
    }
    
    for(int i = 0; i < tickets.size(); ++i){
        if (!visited[i] && tickets[i][0] == curr){
            visited[i] = true;
            dfs(tickets[i][1], tickets, visited, path, depth + 1);
            if (finished) return;
            visited[i] = false;
        }
    }
    
    path.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    
    vector<bool> visited(tickets.size(), false);
    vector<string> path;
    
    dfs("ICN", tickets, visited, path, 0);
    return answer;
}