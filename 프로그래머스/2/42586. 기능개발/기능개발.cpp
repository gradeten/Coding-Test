#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    for(int i = 0; i < progresses.size(); i++){
        int a = ceil((100.0 - progresses[i]) / speeds[i]);
        q.push(a);
    }
    
    while (!q.empty()) {
        int current = q.front(); q.pop();
        int count = 1;

        // 앞에 하나 pop했으니 q가 비었는지 꼭 확인해야 함
        while (!q.empty() && q.front() <= current) {
            q.pop();
            count++;
        }

        answer.push_back(count);
    }

    return answer;
}