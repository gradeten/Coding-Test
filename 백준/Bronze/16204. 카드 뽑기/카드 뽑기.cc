#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    int front_o = m;
    int front_x = n-m;
    int back_o = k;
    int back_x = n-k;
    
    cout << min(front_o, back_o) + min(front_x, back_x);
}