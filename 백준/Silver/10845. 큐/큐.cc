#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    queue<int> Q;
    
    for(int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        int a;
        
        if(s == "push")
        {
            cin >> a;
            Q.push(a);
        }
        else if(s == "pop")
        {
            if (Q.empty()) cout << -1 << "\n";
            else
            {
                cout << Q.front() << "\n";
                Q.pop();
            }
        }
        else if (s == "front")
        {
            if (Q.empty()) cout << -1 << "\n";
            else cout << Q.front() << "\n";
        }
        else if (s == "back")
        {
            if (Q.empty()) cout << -1 << "\n";
            else cout << Q.back() << "\n";
        }
        else if (s == "size") cout << Q.size() << "\n";
        else if (s == "empty")
        {
            if (Q.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }
}