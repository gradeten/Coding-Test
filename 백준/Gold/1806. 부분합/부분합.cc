#include <bits/stdc++.h>
using namespace std;
int n, s;
int arr[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    int en = 0;
    int ans = 0x7fffffff;
    int sum = arr[0];
    
    for(int st = 0; st < n; st++){
        while(en < n && sum < s){
            en++;
            if (en != n) sum += arr[en];
        }
        if (en == n) break;
        ans = min(ans, en - st + 1);
        sum -= arr[st];
    }
    if (ans != 0x7fffffff) cout << ans;
    else cout << 0;
}