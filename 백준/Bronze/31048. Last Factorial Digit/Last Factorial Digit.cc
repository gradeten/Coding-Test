#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    int n;
    while(t--){
        cin >> n;
        int fact = 1;
        for(int i = 1; i <= n; i++){
            fact *= i;
        }
        cout << fact % 10 << '\n';
    }
}