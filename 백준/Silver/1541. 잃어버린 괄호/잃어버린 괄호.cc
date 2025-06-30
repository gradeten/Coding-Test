#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    int num = 0;
    int sign = 1;
    
    string s; cin >> s;
    for(char c : s){
        if (c == '-' || c == '+'){
            ans += (sign * num);
            num = 0;
            if (c == '-') sign = -1;
        }
        else{ 
           num = num*10 + (c - '0');
        }
    }
    ans += (sign * num);
    
    cout << ans;
}