#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int l, n, a;
    vector<int> v;
    
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