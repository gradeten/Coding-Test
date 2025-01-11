#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a;
    string s = "EABCD";
    
    for(int i = 0; i < 3; i++)
    {
        int count = 0;
        for(int j = 0; j < 4; j++)
        {
            cin >> a;
            if (a == 0) count++;
        }
        cout << s[count] << "\n";
    }
}