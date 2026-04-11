#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int i, j, k;
    
    for(int d = 0; d < commands.size(); d++){
        vector<int> temp;
        i = commands[d][0]; j = commands[d][1]; k = commands[d][2];
        for(int x = i-1; x <= j-1; x++) temp.push_back(array[x]);
        sort(temp.begin(), temp.end());
        answer.push_back(temp[k-1]);
    }
    
    return answer;
}