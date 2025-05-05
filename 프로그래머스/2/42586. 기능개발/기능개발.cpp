#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    int day = 0;
    int work = 0;
    
    for(int i = 0; i < progresses.size(); i++){
        int a = ((100 - progresses[i])/speeds[i]);
        if ((a*speeds[i] + progresses[i]) < 100){
            a++;
        }
        q.push(a);
    }
    
    day = q.front(); q.pop(); work++;
    while(!q.empty()){
        if (day >= q.front()){
            work++;
            q.pop();
        }
        else{
            answer.push_back(work);
            work = 0;
            day = q.front(); q.pop(); work++;
        }
    }
    if (work != 0) answer.push_back(work);
    
    return answer;
}