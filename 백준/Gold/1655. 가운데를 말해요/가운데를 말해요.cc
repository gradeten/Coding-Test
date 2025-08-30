#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x;
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
    
    cin >> n; cin >> x;
    maxh.push(x); n--;
    cout << x << '\n';
    
    while(n--){
        cin >> x;
        if (x <= maxh.top()) maxh.push(x);
        else minh.push(x);
        
        if (maxh.size() > minh.size() + 1){
            minh.push(maxh.top());
            maxh.pop();
        }
        if (minh.size() > maxh.size()){
            maxh.push(minh.top());
            minh.pop();
        }
        
        cout << maxh.top() << '\n';
    }
}