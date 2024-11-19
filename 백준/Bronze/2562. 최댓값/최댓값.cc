#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int a, max, index;
    
    cin >> a;
    max = a;
    index = 1;
    
    for(int i = 2; i <= 9; i++)
    {
        cin >> a;
        if (max < a) 
        {
            max = a;
            index = i;
        }
    }
    
    cout << max << endl << index;
}