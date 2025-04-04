#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int money;
    cin >> money;
    
    cout << money - money * 22 / 100 << ' ';
    cout << money * 80 / 100 + money * 20 / 100 * 78 / 100;
}