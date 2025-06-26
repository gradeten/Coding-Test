#include <bits/stdc++.h>
using namespace std;
int n, k;
int d[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    vector<pair<int,int>> item(n);
    for(int i = 0; i < n; i++){
        cin >> item[i].first >> item[i].second;
    }
    
    
    for(int i = 0; i < n; i++){
        int w = item[i].first;
        int v = item[i].second;
        for(int j = k; j >= w; j--){
            d[j] = max(d[j], d[j - w] + v);
        }
    }
    
    cout << d[k];
}