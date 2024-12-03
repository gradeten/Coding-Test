#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m, n;
    int a, b, t;
    
    cin >> m >> n;
    
    vector<int> v(m);
    
    for(int i = 0; i < m; i++)
    {
        v[i] = i+1;
    }
    
    for(int j = 0; j < n; j++)
    {
        cin >> a >> b;
        t = v[b-1];
        v[b-1] = v[a-1];
        v[a-1] = t;
    }
    
    for (int element: v)
    {
        cout << element << " ";
    }
}