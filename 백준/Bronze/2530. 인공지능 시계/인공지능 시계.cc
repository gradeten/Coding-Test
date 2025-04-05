#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    c += d % 60;
    b += (d / 60) % 60;
    a += d / 3600;

    b += c / 60;
    c %= 60;
    
    a += b / 60;
    b %= 60;
    
    a %= 24;
    
    cout << a << ' ' << b << ' ' << c;
}