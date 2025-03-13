#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while(t--){
        long long lt, wt, le, we;
        cin >> lt >> wt >> le >> we;
        
        long long T = lt*wt;
        long long E = le*we;
        
        
        if (T > E) cout << "TelecomParisTech";
        else if (T == E) cout << "Tie";
        else cout << "Eurecom";
        
        cout << '\n';
    }
}