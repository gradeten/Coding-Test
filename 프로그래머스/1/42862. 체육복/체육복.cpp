#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student(n,1);
    for(int i = 0; i < lost.size(); i++) student[lost[i]-1]--;
    for(int i = 0; i < reserve.size(); i++) student[reserve[i]-1]++;
    
    for(int i = 0; i < n; i++){
        if (student[i] > 0) continue;
        if (i != 0){
            if (student[i-1] == 2){
                student[i]++; student[i-1]--; continue;
            }
        }
        if (i != n-1){
            if (student[i+1] == 2){
                student[i]++; student[i+1]--; continue;
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        if (student[i] > 0) answer++;
    }
    
    return answer;
}