#include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int s, f;
    cin >> s >> f;
    
    if (s > f) cout << "flight";
    else cout << "high speed rail";
}