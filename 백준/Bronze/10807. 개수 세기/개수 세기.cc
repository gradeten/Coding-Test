#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, a, t;
    vector<int> v;
    int answer = 0;
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    
    cin >> t;
    
    for(int i = 0; i < n; i++)
    {
        if (v[i] == t)
        {
            answer++;
        }
    }
    
    cout << answer;
}