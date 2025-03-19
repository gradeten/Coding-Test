#include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    int jack;
    cin >> n >> m;
    int arr[n];
    int zero[n];
    
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) (i < 3) ? zero[i] = 0 : zero[i] = 1;
    
    sort(arr,arr+n);
    
    do{
        int sum = 0;
        for(int i = 0; i < n; i++){
            if (zero[i] == 0) sum += arr[i];
        }
        if (abs(sum-m) < abs(jack-m) && sum <= m) jack = sum;
    } while(next_permutation(zero,zero+n));
    
    cout << jack;
}