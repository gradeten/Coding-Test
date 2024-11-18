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
    
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    
    max = *max_element(v.begin(), v.end());
    min = *min_element(v.begin(), v.end());
    
    cout << min << " " << max;
}