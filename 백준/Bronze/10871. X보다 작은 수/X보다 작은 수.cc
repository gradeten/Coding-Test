#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int l, n, a;
    cin >> l;
    cin >> n;
    
    for(int i = 0; i < l; i++)
    {
        cin >> a;
        if (a < n)
        {
            cout << a << " ";
        }
    }
}