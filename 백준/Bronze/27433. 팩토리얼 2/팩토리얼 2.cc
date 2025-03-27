#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    long long fact = 1;;
    
    if (n == 0) cout << fact;
    else{
        for(int i = 1; i <= n; i++){
            fact *= i;
        }
        cout << fact;
    }
}