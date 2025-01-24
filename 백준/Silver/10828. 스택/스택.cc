#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    stack<int> S;
    
    for(int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        
        if(s == "push")
        {
            int num;
            cin >> num;
            S.push(num);
        }
        else if(s == "pop")
        {
            if (S.empty()) cout << -1 << "\n";
            else
            {
                cout << S.top() << "\n";
                S.pop();
            }
        }
        else if(s == "top")
        {
            if (S.empty()) cout << -1 << "\n";
            else cout << S.top() << "\n";
        }
        else if(s == "size")
        {
            cout << S.size() << "\n";
        }
        else if(s == "empty")
        {
            if (S.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }
}