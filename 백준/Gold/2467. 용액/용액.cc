#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
int arr[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    int left = 0;
    int right = n-1;
    
    ll best_sum = 1e18;
    int ans_left = 0, ans_right = n - 1;
    
    while(left < right){
        ll sum = arr[left] + arr[right];
        
        if (abs(sum) < best_sum) {
            best_sum = abs(sum);
            ans_left = left;
            ans_right = right;
        }
        
        if (sum < 0) left++;
        else right--;
    }
    cout << arr[ans_left] << ' ' << arr[ans_right];
}