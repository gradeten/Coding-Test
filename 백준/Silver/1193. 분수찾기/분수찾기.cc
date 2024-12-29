#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int sum = 0;
    int i = 0;
    int numerator, denominator;
    
    while (n > sum)
    {
        i++;
        sum += i;
    }
    
    int diff = sum - n;
    
    if (i % 2 == 0)
    {
        numerator = i - diff;
        denominator = 1 + diff;
    }
    else
    {
        numerator = 1 + diff;
        denominator = i - diff;
    }
    
    cout << numerator << "/" << denominator;
    return 0;
    
    
}