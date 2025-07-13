#include <bits/stdc++.h>
using namespace std;
int n, m;

int count(int n, int x){
    int res = 0;
    for (long long i = x; i <= n; i *= x) {
        res += n / i;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    int total_5 = count(n, 5) - count(n-m, 5) - count(m, 5);
    int total_2 = count(n, 2) - count(n-m, 2) - count(m, 2);
    cout << min(total_5, total_2);
}