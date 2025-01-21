#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    list<char> C;
    for(int i = 0; i < s.size(); i++) C.push_back(s[i]);
    auto t = C.end();
    
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        char c;
        cin >> c;
        if (c == 'L' && t != C.begin()) t--;
        else if (c == 'D' && t != C.end()) t++;
        else if (c == 'B' && t != C.begin())
        {
            t = C.erase(--t); // Decrement first, then erase, and update iterator
        }
        else if (c == 'P')
        {
            char letter;
            cin >> letter;
            C.insert(t, letter);
        }
    }
    
    for(auto i : C) cout << i;
}
