#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
ll arr[5005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr,arr+n);
    
    ll best_sum = 1e18;
    int ans_i = 0, ans_left = 1, ans_right = n - 1;
    
    for(int i = 0; i < n-2; i++){
        int left = i + 1;
        int right = n - 1;
        
        while(left < right){
            ll sum = arr[i] + arr[left] + arr[right];
            
            if (abs(sum) < abs(best_sum)){
                best_sum = sum;
                ans_left = left;
                ans_right = right;
                ans_i = i;
            }
            
            if (sum < 0) left++;
            else right--;
        }
    }
    
    cout << arr[ans_i] << ' ' << arr[ans_left] << ' ' << arr[ans_right];
}