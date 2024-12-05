#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int a;
    
    cin >> a;
    v.push_back(a%42);
    
    for(int i = 0; i < 9; i++)
    {
        int flag = 0;
        cin >> a;
        a %= 42;
        
        for(int j = 0; j < v.size(); j++)
        {
            if (v[j] == a)
            {
                flag = 1;
                break;
            }
        }
        
        if (flag == 0)
        {
            v.push_back(a);
        }
    }
    
    cout << v.size();
}