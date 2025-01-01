#include <iostream>
using namespace std;

int main()
{
    int n, k;
    int num = 0;
    cin >> n >> k;
    
    for(int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            num++;
            
            if (num == k)
            {
                cout << i;
                break;
            }
        }
    }
    
    if (num != k)
    {
        cout << 0;
    }
}