#include <bits/stdc++.h>
using namespace std;
const int m = 123456 * 2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    
    vector<bool> state(m + 1, true);
    
    state[1] = false;
    for(int i = 2; i * i <= m; i++){
        if (!state[i]) continue;
        for(int j = i * i; j <= m; j += i){
            state[j] = false;
        }
    }
    
    while(true){
        cin >> n;
        if (n == 0) break;
        
        int cnt = 0;
        
        for(int i = n+1; i <= 2*n; i++){
            if (state[i]) cnt++;
        }
        
        cout << cnt << '\n';
    }
}