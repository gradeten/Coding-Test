//
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    vector<int> sushi(n);
    for(int i = 0; i < n; i++) cin >> sushi[i];
    
    vector<int> cnt(d + 1, 0);
    int distinct = 0;
    for(int i = 0; i < k; i++){
        if(cnt[sushi[i]] == 0) distinct++;
        cnt[sushi[i]]++;
    }
    
    int ans = distinct + (cnt[c] == 0 ? 1 : 0);
    for(int i = 1; i < n; i++){
        cnt[sushi[i-1]]--;
        if (cnt[sushi[i-1]] == 0) distinct--;
        int right = sushi[(i + k - 1) % n];
        if (cnt[right] == 0) distinct++;
        cnt[right]++;
        ans = max(ans, distinct + (cnt[c] == 0 ? 1 : 0));
    }
    
    cout << ans;
}