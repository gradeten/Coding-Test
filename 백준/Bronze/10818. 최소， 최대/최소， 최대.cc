#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, a, max, min;
    vector<int> v;
    
    cin >> n;
    cin >> a;
    min = a;
    max = a;
    
    v.push_back(a);
    
    for(int i = 1; i < n; i++)
    {
        cin >> a;
        if (a > max) max = a;
        if (a < min) min = a;
    }
    
    cout << min << " " << max;
}