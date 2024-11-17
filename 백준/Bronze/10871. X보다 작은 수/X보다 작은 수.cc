#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int l, n, a;
    vector<int> v;
    
    cin >> l;
    cin >> n;
    
    for(int i = 0; i < l; i++)
    {
        cin >> a;
        if (a < n)
        {
            v.push_back(a);
        }
    }
    
    for(int num : v)
    {
        cout << num << " ";
    }
}