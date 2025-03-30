#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n = 6;
    int win = 0;
    
    while(n--){
        char c;
        cin >> c;
        if (c == 'W') win++;
    }
    
    if (win == 5 || win == 6) cout << 1;
    else if (win == 3 || win == 4) cout << 2;
    else if (win == 1 || win == 2) cout << 3;
    else cout << -1;
}