#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, a, b;
    vector<int> v;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++)
    {
        v.push_back(i+1);
    }
    
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        reverse(v.begin() + (a-1), v.begin() + b);
    }
    
    for(int element : v)
    {
        cout << element << " ";
    }
}