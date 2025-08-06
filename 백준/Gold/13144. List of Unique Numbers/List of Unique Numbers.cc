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
    
    unordered_set<int> s;
    int en = 0; 
    ll ans = 0;
    for(int st = 0; st < n; st++){
        while (en < n && s.find(arr[en]) == s.end()){
            s.insert(arr[en]);
            en++;
        }
        ans += (en - st);
        s.erase(arr[st]);
    }
    
    cout << ans;
}