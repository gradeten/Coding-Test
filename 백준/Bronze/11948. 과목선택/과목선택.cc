#include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    
    int m1,m2;
    m1 = min(min(a,b),min(c,d));
    m2 = min(e,f);
    
    cout << a+b+c+d+e+f-m1-m2;
}