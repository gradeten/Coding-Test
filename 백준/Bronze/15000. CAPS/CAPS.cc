#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    for (char& c : s){
        c = toupper(c);
    }
    
    cout << s;
}