#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x;
    long long ans = 0;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(n--){
        cin >> x;
        pq.push(x);
    }
    
    if (n == 1){
        cout << pq.top();
        return 0;
    }
    
    while(pq.size() > 1){
       int first = pq.top(); pq.pop();
       int second = pq.top(); pq.pop();
       
       int merged = first + second;
       ans += merged;
       pq.push(merged);
    }
    
    cout << ans;
}