#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int sum = 0;
    int answer = 0;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    
    sort(v.begin(), v.end());
    
    for(int i = 0; i < n; i++){
        sum += v[i];
        answer += sum;
    }
    
    cout << answer;
}