#include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    while(N--){
        string s;
        cin >> s;
        if (s.length() >= 6 && s.length() <= 9) cout << "yes";
        else cout << "no";
        cout << '\n';
    }
}