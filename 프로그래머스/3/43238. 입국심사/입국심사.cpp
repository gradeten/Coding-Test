#include <bits/stdc++.h>
using namespace std;

bool solve(long long x, vector<int> times, int n){
    long long cur = 0;
    for(int i = 0; i < times.size(); i++){
        cur += x/times[i];
        if (cur >= n) return true;
    }
    if (cur >= n) return true;
    else return false;
}

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    
    long long st = 1;
    long long en = (long long)n*times[times.size()-1];
    
    while(st < en){
        long long mid = (st + en)/2;
        if (solve(mid, times, n)) en = mid;
        else st = mid + 1;
    }
    
    return st;
}