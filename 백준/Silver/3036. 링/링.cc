#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    int rings[n];
    for(int i = 0; i < n; i++) cin >> rings[i];
    
    int first = rings[0];
    for(int i = 1; i < n; i++){
        int g = gcd(first, rings[i]);
        cout << first/g << '/' << rings[i]/g << '\n';
    }
}