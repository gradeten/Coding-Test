#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int n;
    int a;
    string s;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        cin >> s;
        
        for(int k = 0; k < s.size(); k++)
        {
            for(int j = 0; j < a; j++)
            {
                cout << s[k];
            }
        }
        
        cout << endl;
    }
}