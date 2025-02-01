#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    getline(cin, s);
    
    while (s != ".")
    {
        stack<char> S;
        bool isOk = true;
        
        for(int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' or s[i] == '[')
            {
                S.push(s[i]);
            }
            else if (s[i] == ')')
            {
                if (!S.empty() && S.top() == '(') S.pop();
                else
                {
                    isOk = false;
                    break;
                }
            }
            else if (s[i] == ']')
            {
                if (!S.empty() && S.top() == '[') S.pop();
                else
                {
                    isOk = false;
                    break;
                }
            }
        }
        
        if (isOk && S.empty()) cout << "yes\n";
        else cout << "no\n";
        
        getline(cin, s);
    }
}
