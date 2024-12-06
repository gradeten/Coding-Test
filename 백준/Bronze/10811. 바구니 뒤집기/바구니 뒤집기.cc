#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, a, b;
    vector<int> v;
    vector<int> vt;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++)
    {
        v.push_back(i+1);
    }
    
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        vt = v;
        for(int j = a; j <= b; j++)
        {
            v[j-1] = vt[a+b-j-1];
        }
    }
    
    for(int element : v)
    {
        cout << element << " ";
    }
}