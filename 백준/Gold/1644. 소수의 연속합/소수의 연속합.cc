#include <bits/stdc++.h>
using namespace std;
int n;
int primenum[4000005];
vector<int> prime;

void getprime(){
    for(int i = 2; i <= n; i++) primenum[i] = i;
    
    for(int i = 2; i <= sqrt(n); i++){
        if (primenum[i] == 0) continue;
        for(int j = i * i; j <= n; j += i){
            primenum[j] = 0;
        }
    }
    
    for(int i = 2; i <= n; i++){
        if (primenum[i] != 0) prime.push_back(i);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    if (n == 1){
        cout << 0;
        return 0;
    }
    getprime();
    
    int s = prime.size();
    int tot = prime[0];
    int en = 0;
    int ans = 0;
    for(int st = 0; st < s; st++){
        while (en < s && tot < n){
            en++;
            if (en != n) tot += prime[en];
        }
        if (en == n) break;
        if (tot == n) ans++;
        tot -= prime[st];
    }
    
    cout << ans;
}