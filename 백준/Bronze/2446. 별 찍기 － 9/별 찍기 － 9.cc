#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for(int i = 0; i <= N-1; i++)
    {
        for(int j = 0; j < i; j++) cout << " ";
        for(int k = (N - i)*2 - 1; k > 0; k--) cout << "*";
        cout << "\n";
    }
    for(int i = N-2; i >= 0; i--)
    {
        for(int j = 0; j < i; j++) cout << " ";
        for(int k = (N - i)*2 - 1; k > 0; k--) cout << "*";
        cout << "\n";
    }
}