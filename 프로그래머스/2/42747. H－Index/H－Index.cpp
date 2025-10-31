#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0; 
    int sz = citations.size(); 
    sort(citations.begin(), citations.end());
    
    
    for (int i = citations[sz-1]; i >= 0; i--){
        int cnt = 0;
        
        for(int j = 0; j < sz; j++){
            if (citations[j] >= i) cnt++;
        }
        if (cnt >= i && sz - cnt <= i){
            answer = i;
            break;
        }
    }
    
    return answer;
}