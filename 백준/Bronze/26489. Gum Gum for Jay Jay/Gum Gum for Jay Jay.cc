#include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string line;
    int cnt = 0;
    
    while(getline(cin,line)){
        cnt++;
    }
    
    cout << cnt;
    return 0;
}