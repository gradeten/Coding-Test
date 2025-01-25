#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    stack<int> S;
    string answer;
    int cnt = 1;

    while(n--)
    {
        int t;
        cin >> t;
        while (cnt <= t)
        {
            S.push(cnt++);
            answer += "+\n";
        }
        if (S.top() != t)
        {
            cout << "NO";
            return 0;
        }
        S.pop();
        answer += "-\n";
     }
    
     cout << answer;

}