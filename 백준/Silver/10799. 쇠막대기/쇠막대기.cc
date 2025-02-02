#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    stack<char> S;
    int answer = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            S.push(s[i]);
        }
        else
        {
            if (s[i-1] == '(')
            {
                S.pop();
                answer += S.size();
            }
            else
            {
                S.pop();
                answer++;
            }
        }
    }
    
    cout << answer;
}