#include <bits/stdc++.h>
using namespace std;
int t, n;
int zero[41];
int one[41];

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    zero[0] = 1; zero[1] = 0;
    one[0] = 0; one[1] = 1;
    for(int i = 2; i <= 40; i++){
        zero[i] = zero[i-2] + zero[i-1];
        one[i] = one[i-2] + one[i-1];
    }
    
    cin >> t;
    while(t--){
        cin >> n;
        cout << zero[n] << ' ' << one[n] << '\n';
    }
}