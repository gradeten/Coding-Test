#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    vector<int> a;
    vector<int> b;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        a.push_back(t);
    }
    
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        b.push_back(t);
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += (a[i]*b[i]);
    }
    cout << sum;
}