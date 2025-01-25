#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    stack<int> S;
    vector<char> v;

    int num[n];
    int a = 1;
    
    for(int i = 0; i < n; i++) cin >> num[i];

    for(int i = 0; i < n; i++)
    {
        while (S.empty() || num[i] > S.top())
        {
            S.push(a);
            v.push_back('+');
            a++;
        }
        if (num[i] == S.top())
        {
            S.pop();
            v.push_back('-');
        }
        else break;
        
    }
    
    if (S.empty()) for (char c : v) cout << c << "\n";
    else cout << "NO";

}