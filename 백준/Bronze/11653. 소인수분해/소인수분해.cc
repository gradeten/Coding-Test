#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    for(int i = 2; i <=n; i++)
    {
        while (n % i == 0 && n != 1)
        {
            cout << i << endl;
            n /= i;
        }
    }
}