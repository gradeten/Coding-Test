#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    int i = 0;
    int a, b;
    
    while (n > sum)
    {
        i++;
        sum += i;
    }
    
    if (i % 2 == 0)
    {
        a = i;
        b = 1;

        for(int j = sum; j > n; j--)
        {
            a--;
            b++;
        }
    }
    else
    {
        a = 1;
        b = i;
        
        for(int j = sum; j > n; j--)
        {
            a++;
            b--;
        }
    }
    
    cout << a << "/" << b;
    
    
}