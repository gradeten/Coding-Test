#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num[9], a, b;
    int diff = 0;
    vector<int> v;
    
    for (int i = 0; i < 9; i++) 
    {
        cin >> num[i];
        diff = diff + num[i];
    }
    diff = diff - 100;
    
    bool found = false;
    for (int i = 0; i <= 7 && !found; i++) 
    {
        for(int j = i + 1; j <= 8; j++)
        {
            if ((num[i] + num[j]) == diff) 
            {
                a = i;
                b = j;
                found = true;
            }
        }
    }
    
    for(int i = 0; i < 9; i++)
    {
        if (i != a && i != b) v.push_back(num[i]); 
    }
    
    sort(v.begin(), v.end());
    
    for(int i = 0; i < 7; i++)
    {
        cout << v[i] << "\n";
    }
        
}