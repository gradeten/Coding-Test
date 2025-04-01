#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int s, n, m, input;
    int u = 0;
    cin >> s >> n >> m;
    
    for(int i = 0; i < n+m; i++){
        cin >> input;
        if (input == 1){
            u++;
            if (u > s) s = s*2;
        }
        else{
            u--;
        }
    }
    
    cout << s;
}