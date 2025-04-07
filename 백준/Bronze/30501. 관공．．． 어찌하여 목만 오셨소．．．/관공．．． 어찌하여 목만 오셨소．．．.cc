#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    string s;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> s;
        if (s.find('S') != string::npos) cout << s;
    }
}