#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    getline(cin, s);
    string answer = "";
    
    for(int i = 0; i < s.size()-1; i++){
        if (s[i] != s[i+1]) answer += s[i];
    }
    answer+= s[s.size()-1];
    
    cout << answer;
}