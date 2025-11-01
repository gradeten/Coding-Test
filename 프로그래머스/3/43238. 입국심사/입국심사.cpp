#include <bits/stdc++.h>
using namespace std;

bool solve(long long x, vector<int> times,int n){ // x 시간 안에 n명 심사 가능한지
    long long cur = 0;
    for(int i = 0; i < times.size(); i++){
        cur += x/times[i];
    }
    if (cur < n) return false;
    else return true;
}

long long solution(int n, vector<int> times) {
    
    sort(times.begin(), times.end());
    long long st = 1;
    long long en = (long long)times[times.size()-1]*n; 
    
    while( st < en ){
        long long mid = (st + en ) / 2;
        if (solve(mid, times, n)) en = mid; // 시간 덜 필요
        else st = mid + 1; // 시간 더 필요
    }
    
    return st;
}