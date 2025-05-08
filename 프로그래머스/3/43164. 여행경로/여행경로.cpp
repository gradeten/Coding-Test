#include <bits/stdc++.h>
using namespace std;

bool finished = false;
vector<string> answer;

void dfs(string curr, vector<vector<string>>& tickets, vector<bool>& visited, vector<string>& route, int depth){
    route.push_back(curr);
    
    if (depth == tickets.size()){
        answer = route;
        finished = true;
        return;
    }
    for(int i = 0; i < tickets.size(); ++i){
        if (!visited[i] && tickets[i][0] == curr){
            visited[i] = true;
            dfs(tickets[i][1], tickets, visited, route, depth + 1);
            if (finished) return;
            visited[i] = false;
        }
    }
    
    route.pop_back();
}


vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    vector<bool> visited(tickets.size(), false);
    vector<string> route;
    
    dfs("ICN", tickets, visited, route, 0);
    return answer;
}