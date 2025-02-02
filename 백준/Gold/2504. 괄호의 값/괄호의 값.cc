#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    stack<char> S;
    int mul = 1;
    int answer = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            mul *= 2;
            S.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (S.empty() || S.top() != '(')
            {
                answer = 0;
                break;
            }
            if (s[i-1] == '(') answer += mul;
            mul /= 2;
            S.pop();
        }
        else if (s[i] == '[')
        {
            mul *= 3;
            S.push(s[i]);
        }
        else if (s[i] == ']')
        {
            if (S.empty() || S.top() != '[')
            {
                answer = 0;
                break;
            }
            if (s[i-1] == '[') answer += mul;
            mul /= 3;
            S.pop();
        }
    }
    
    if (!S.empty()) cout << 0;
    else cout << answer;
}