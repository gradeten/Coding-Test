#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<long long> v(n);  // long long으로 변경
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    int cnt = 1;
    int max_cnt = 1;
    long long answer = v[0];  // long long으로 변경
    
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i - 1]) {
            cnt++;
        } else {
            cnt = 1;
        }
        
        if (cnt > max_cnt) {
            max_cnt = cnt;
            answer = v[i];
        }
    }

    cout << answer;
}
