#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    int arr[50];
    int zero[50];
    
    while(t != 0){
        for(int i = 0; i < t; i++) cin >> arr[i];
        for(int i = 0; i < t; i++) (i < 6) ? zero[i] = 0 : zero[i] = 1;
        
        do{
            for(int i = 0; i < t; i++){
                if (zero[i] == 0) cout << arr[i] << ' ';
            }
            cout << '\n';
        } while(next_permutation(zero,zero+t));
        
        cout << '\n';
        cin >> t;
    }
}