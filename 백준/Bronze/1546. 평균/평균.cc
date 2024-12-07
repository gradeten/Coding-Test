#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    float max, sum, a = 0;
    vector<float> v;
    
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    max = *max_element(v.begin(), v.end());
    
    for(int i = 0; i < n; i++)
    {
        v[i] = v[i]/max*100;
    }
    
    for(int i = 0; i < n; i++)
    {
        sum += v[i];
    }
    
    cout << sum/(n*1.0);
}