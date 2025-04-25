#include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while(t--){
        int a;
        cin >> a;
        if (a % 2 == 0){
            cout << a;
            cout << " is even\n";
        }
        else{
            cout << a;
            cout << " is odd\n";
        }
    }
}