#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b, c;
    cin >> a >> b >> c;
    
    if (a < b && a < c)
    {
        if (b < c)
        {
            cout << a << " " << b << " " << c;
        }
        else
        {
            cout << a << " " << c << " " << b;
        }
    }
    else if (b < c && b < a)
    {
        if (a < c)
        {
            cout << b << " " << a << " " << c;
        }
        else
        {
            cout << b << " " << c << " " << a;
        }
    }
    else
    {
        if (a < b)
        {
            cout << c << " " << a << " " << b;
        }
        else
        {
            cout << c << " " << b << " " << a;
        }
    }
}