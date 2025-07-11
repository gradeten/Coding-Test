#include <bits/stdc++.h>
using namespace std;
vector<bool> state(1005, true);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    int cnt = 0;
    
    for(int i = 2; i <= n; i++){
        if (!state[i]) continue;
        for(int j = i; j <= n; j+= i){
            if (!state[j]) continue;
            state[j] = false;
            cnt++;
            if (cnt == k) {cout << j; return 0;}
        }
    }
}