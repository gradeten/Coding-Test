#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[200005];
int cnt[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    int st = 0; int en = 0;
    int ans = 0;
    cnt[arr[st]]++;
    for(st = 0; st < n; st++){
        while(en < n-1 && cnt[arr[en+1]] < k){
            en++;
            cnt[arr[en]]++;
        }
        ans = max(ans, en - st + 1);
        cnt[arr[st]]--;
    }
    
    cout << ans;
}