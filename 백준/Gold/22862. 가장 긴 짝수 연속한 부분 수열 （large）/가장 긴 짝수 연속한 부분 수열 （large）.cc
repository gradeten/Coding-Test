#include <bits/stdc++.h>
using namespace std;
int n, k;
long long arr[1000005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    int st = 0; int en = 0;
    int odd_count = 0;
    int max_length = 0;
    
    while(en < n){
        if (arr[en] % 2 == 0){
            en++;
        }
        else{
            if (odd_count < k){
                odd_count++;
                en++;
            }
            else{
                if (arr[st] % 2 != 0) odd_count--;
                st++;
            }
        }
        
        max_length = max(max_length, en - st - odd_count);
    }
    
    cout << max_length;
}