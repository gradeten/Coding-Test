#include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int arr[2][26] = {0};
    int ans = 0;
    string s1, s2;
    cin >> s1 >> s2;
    
    for(char c : s1) arr[0][c-'a']++;
    for(char c : s2) arr[1][c-'a']++;
    
    for(int i = 0; i < 26; i++) ans += abs(arr[0][i] - arr[1][i]);
        
    cout << ans;
}