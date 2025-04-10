#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    int answer = 0;
    
    for(int i = 0; i < s.size(); i++){
        char c;
        c = s[i];
        if (s[i+1] == '0'){answer += 10; i++;}
        else answer += (c - '0');
    }
    
    cout << answer;
}
