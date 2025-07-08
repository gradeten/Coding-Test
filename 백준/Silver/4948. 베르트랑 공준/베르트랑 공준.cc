#include <bits/stdc++.h>
using namespace std;
vector<bool> state(247000, true);



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    
    state[1] = false;
    for(int i = 2; i <= 246912; i++){
        if (!state[i]) continue;
        for(int j = i * 2; j <= 246912; j += i){
            if (!state[j]) continue;
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