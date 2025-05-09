#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    stack<int> S;
    
    int K;
    cin >> K;
    int sum = 0;
    
    while(K--)
    {
        int n;
        cin >> n;
        
        if (n != 0) S.push(n);
        else if (!S.empty()) S.pop();
    }
    
    while(!S.empty())
    {
        sum += S.top();
        S.pop();
    }
    
    cout << sum;
    
}