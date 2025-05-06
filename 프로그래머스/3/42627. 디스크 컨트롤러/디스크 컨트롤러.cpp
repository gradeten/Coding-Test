#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0, time = 0, idx = 0;
    int count = 0;
    int n = jobs.size();

    sort(jobs.begin(), jobs.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    while (count < n) {
        
        while (idx < n && jobs[idx][0] <= time) {
            pq.push({jobs[idx][1], jobs[idx][0]}); // {작업시간, 요청시간}
            idx++;
        }

        if (!pq.empty()) {
            auto [dur, start] = pq.top(); pq.pop();
            time += dur;
            answer += time - start;
            count++;
        } else {
            // 대기 중인 작업이 없으면 시간 한 칸 이동
            time = jobs[idx][0];
        }
    }

    return answer / n;
}
