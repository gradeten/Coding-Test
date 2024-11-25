#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    
    for(int i = 97; i <= 122; i++)
    {
        bool found = false;
        for(int j = 0; j < s.size(); j++)
        {
            if (char(i) == s[j])
            {
                cout << j << " ";
                found = true;
                break;
            }
        }
        
        if (!found)
        {
            cout << -1 << " ";
        }
    }
}