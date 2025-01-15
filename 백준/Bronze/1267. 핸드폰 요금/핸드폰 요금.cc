#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, n;
    cin >> N;
    int y = 0, m = 0;
    
    for(int i = 0; i < N; i++)
    {
        cin >> n;
        y += (n/30+1)*10;
        m += (n/60+1)*15;
    }
    
    if (y < m)
    {
        cout << "Y " << y; 
    }
    else if (m < y)
    {
        cout << "M " << m; 
    }
    else
    {
        cout << "Y M " << m; 
    }
}