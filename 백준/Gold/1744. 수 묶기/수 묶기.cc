#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    long long ans = 0;
    vector<int> plus;
    vector<int> minus;
    int zero = 0; int one = 0;
    
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        if (a == 1) one++;
        else if (a > 0) plus.push_back(a);
        else if (a == 0) zero++;
        else if (a < 0) minus.push_back(a);
    }
    
    sort(plus.begin(), plus.end(), greater<int>());
    sort(minus.begin(), minus.end());
    
    if (plus.size() % 2 == 0){
        for(int i = 0; i < plus.size(); i +=2) ans += (plus[i]*plus[i+1]);
    }
    else{
        for(int i = 0; i < plus.size()-1; i +=2) ans += (plus[i]*plus[i+1]);
        ans += plus.back();
    }
    
    if (minus.size() % 2 == 0){
        for(int i = 0; i < minus.size(); i +=2) ans += (minus[i]*minus[i+1]);
    }
    else{
        for(int i = 0; i < minus.size()-1; i +=2) ans += (minus[i]*minus[i+1]);
        if (zero == 0){
            ans += minus.back();
        }
    }
    
    ans += one;
    
    cout << ans;
}