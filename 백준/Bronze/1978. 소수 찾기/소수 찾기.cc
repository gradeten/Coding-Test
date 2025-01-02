#include <iostream>
using namespace std;

int main()
{
    int n, a;
    cin >> n;
    
    bool isComposite;
    int sum = 0;
    
    for(int i = 0; i < n; i++)
    {
        isComposite = false;
        cin >> a;
        for(int j = 2; j <= a/2; j++)
        {
            if (a % j == 0)
            {
                isComposite = true;
                break;
            }
        }
        
        if(!isComposite&&a!=1) sum++;
    }
    
    cout << sum;
}