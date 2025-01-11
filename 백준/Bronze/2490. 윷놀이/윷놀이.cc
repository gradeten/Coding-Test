#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a;
    char c;
    
    for(int i = 0; i < 3; i++)
    {
        int count = 0;
        for(int j = 0; j < 4; j++)
        {
            cin >> a;
            if (a == 0) count++;
        }
        if (count == 0) 
        {
            cout << "E\n";
        }
        else
        {
            c = count + 64;
            cout << c << "\n";
        }
    }
}