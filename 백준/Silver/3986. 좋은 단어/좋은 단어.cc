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
            if (c == 'A')
            {
                if (!S.empty() && S.top() == 'A') S.pop();
                else S.push(c);
            }
            else if (c == 'B')
            {
                if (!S.empty() && S.top() == 'B') S.pop();
                else S.push(c);
            }
        }
        
        if (S.empty()) answer++;
    }
    
    cout << answer;
}