#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    int answer = 0;
    
    while(N--)
    {
        stack<char> S;
        string s;
        cin >> s;
        
        for(char c : s)
        {
            if (!S.empty() && S.top() == c) S.pop();
            else S.push(c);
        }
        
        if (S.empty()) answer++;
    }
    
    cout << answer;
}