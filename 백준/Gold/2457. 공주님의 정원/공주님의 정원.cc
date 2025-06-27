#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> flower;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while(n--){
        int m1, d1, m2, d2;
        cin >> m1 >> d1 >> m2 >> d2;
        flower.push_back({m1 * 100 + d1, m2 * 100 + d2});
    }
    
    sort(flower.begin(), flower.end());
    
    int current = 301;
    int ans = 0, idx = 0, max_end = 0;
    
    while(current <= 1130){
        bool found = false;
        while(idx < flower.size() && flower[idx].first <= current){
            if (flower[idx].second > max_end){
                max_end = flower[idx].second;
                found = true;
            }
            idx++;
        }
        if (!found){
            cout << 0;
            return 0;
        }
        current = max_end;
        ans++;
    }
    
    
    cout << ans;
}