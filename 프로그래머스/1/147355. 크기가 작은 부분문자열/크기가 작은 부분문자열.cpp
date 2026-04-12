#include <bits/stdc++.h>
using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int s = p.length();
    
    for(int i = 0; i <= t.length() - s; i++){
        if (t.substr(i,s) <= p) answer++;
    }
    
    return answer;
}