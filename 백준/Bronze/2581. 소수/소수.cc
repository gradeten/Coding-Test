#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int sum = 0;
    int least = 0;
    bool isComposite;
    
    
    for(int i = m; i <= n; i++)
    {
        if (i == 1) continue;
        
        isComposite = false;
        for(int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                isComposite = true;
                break;
            }
        }
        if(!isComposite )
        {
            sum += i;
            if (least == 0) least = i;
        }
        
    }
    
    if(sum == 0)
    {
        cout << -1;
    }
    else
    {
        cout << sum << endl;
        cout << least;
    }
}