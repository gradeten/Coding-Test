#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    deque<int> DQ;
    
    while(N--)
    {
        string s;
        cin >> s;
        int a;
        
        if(s == "push_front")
        {
            cin >> a;
            DQ.push_front(a);
        }
        else if(s == "push_back")
        {
            cin >> a;
            DQ.push_back(a);
        }
        else if(s == "pop_front")
        {
            if (DQ.empty()) cout << -1 << "\n";
            else
            {
                cout << DQ.front() << "\n";
                DQ.pop_front();
            }
        }
        else if(s == "pop_back")
        {
            if (DQ.empty()) cout << -1 << "\n";
            else
            {
                cout << DQ.back() << "\n";
                DQ.pop_back();
            }
        }
        else if(s == "size") cout << DQ.size() << "\n";
        else if(s == "empty")
        {
            if (DQ.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if(s == "front")
        {
            if (DQ.empty()) cout << -1 << "\n";
            else cout << DQ.front() << "\n";
        }
        else if(s == "back")
        {
            if (DQ.empty()) cout << -1 << "\n";
            else cout << DQ.back() << "\n";
        }
            
    }
}
