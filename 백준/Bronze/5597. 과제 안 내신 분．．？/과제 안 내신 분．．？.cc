#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a;
    vector<int> v(30,0);
    
    for(int i = 0; i < 28; i++)
    {
        cin >> a;
        v[a-1] = 1;
    }
    
    for(int i = 0; i < 30; i++)
    {
        if (v[i] == 0)
        {
            cout << i + 1 << endl;
        }
    }
}