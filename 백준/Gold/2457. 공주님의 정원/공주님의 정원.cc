#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> flower;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        int m1, d1, m2, d2;
        cin >> m1 >> d1 >> m2 >> d2;
        flower.push_back({m1*100+d1, m2*100+d2});
    }
    
    sort(flower.begin(), flower.end());
    
    int current = 301;
    int idx = 0;
    int ans = 0;
    
    while(current <= 1130){
        int next_end = current;
        while(idx < n && flower[idx].first <= current){
            next_end = max(next_end, flower[idx].second);
            idx++;
        }
        if (next_end == current){
            cout << 0;
            return 0;
        }
        current = next_end;
        ans++;
    }
    cout << ans;
    return 0;
}