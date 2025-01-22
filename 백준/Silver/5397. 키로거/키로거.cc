#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int L;
    cin >> L;
    
    for(int i = 0; i < L; i++)
    {
        string s;
        cin >> s;
        
        list<char> C;
        auto cursor = C.end();
        
        for(int i = 0; i < s.size(); i++)
        {
            if (s[i] == '<')
            {
                if (cursor != C.begin())  cursor--;
                else continue;
            }
            else if (s[i] == '>')
            {
                if (cursor != C.end())  cursor++;
                else continue;
            }
            else if (s[i] == '-')
            {
                if (cursor != C.begin())  cursor = C.erase(--cursor);
                else continue;
            }
            else C.insert(cursor, s[i]);
        }
        
        for (auto i : C) cout << i;
        cout << "\n";
    }
}