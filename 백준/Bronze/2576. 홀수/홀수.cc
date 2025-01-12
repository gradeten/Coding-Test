#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a;
    int min = 100;
    int sum = 0;
    
    for (int i = 0; i < 7; i++)
    {
        cin >> a;
        if (a & 1)
        {
            if (a < min) min = a;
            sum += a;
        }
    }
    
    if (sum == 0)
    {
        cout << -1;
    }
    else
    {
        cout << sum << "\n" << min;
    }
}