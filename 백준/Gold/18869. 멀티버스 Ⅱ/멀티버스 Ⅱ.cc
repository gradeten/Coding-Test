#include <bits/stdc++.h>
using namespace std;
int m, n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    map<vector<int>, int> freq;
    
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        vector<int> x(n), sorted;
        for(int j = 0; j < n; j++){
            cin >> x[j];
            sorted.push_back(x[j]);
        }
        
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        
        vector<int> compressed;
        for(int j = 0; j < n; j++){
            compressed.push_back(lower_bound(sorted.begin(), sorted.end(), x[j]) - sorted.begin());
        }
        
        freq[compressed]++;
    }
    
    long long ans = 0;
    for (auto& [key, cnt] : freq) {
        ans += 1LL * cnt * (cnt - 1) / 2;
    }
    cout << ans;
}