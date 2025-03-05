#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    int arr[n];
    int zero[n];
    
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr,arr+n);
    for(int i = 0; i < n; i++) (i < m) ? zero[i] = 0 : zero[i] = 1;

    do{
        for(int i = 0; i < n; i++)
            if (zero[i] == 0) cout << arr[i] << ' ';
        cout << '\n';
    } while(next_permutation(zero,zero+n));
}