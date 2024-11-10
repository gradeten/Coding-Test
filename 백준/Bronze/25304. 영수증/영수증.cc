#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int total;
    int length;
    int sum = 0;
    int a, b;
    
    cin >> total >> length;
    
    for(int i = 0; i < length; i++)
    {
        cin >> a >> b;
        sum += a*b;
    }
    
    if (sum == total)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}