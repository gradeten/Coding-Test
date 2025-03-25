#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr,arr+3);
    
    string s;
    cin >> s;
    
    for(int i = 0; i < 3; i++){
        cout << arr[s[i]-'A'] << ' ';
    }
}