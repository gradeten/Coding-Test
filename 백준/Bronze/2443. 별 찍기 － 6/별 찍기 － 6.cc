#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for(int i = N; i >= 1; i--)
    {
        for(int j = 0; j < N-i; j++) cout << " ";
        for(int k = 0; k < i*2-1; k++) cout << "*";
        cout << "\n";
    }
}