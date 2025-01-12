#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a;
    int sum = 0;
    vector<int> v;
    
    for(int i = 0; i < 5; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    
    sort(v.begin(), v.end());
    
    for(int i = 0; i < 5; i++)
    {
        sum += v[i];
    }
    
    cout << sum/5 << "\n" << v[2];
}
