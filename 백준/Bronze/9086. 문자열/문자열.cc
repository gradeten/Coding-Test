#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        cout << s[0] << s[s.size()-1] << endl;
    }
}