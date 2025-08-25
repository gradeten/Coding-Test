#include <bits/stdc++.h>
using namespace std;
int n, h, k;
vector<pair<int,int>> v;
multiset<int> teams;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while(n--){
        cin >> h >> k;
        v.push_back({h,k});
    }
    
    sort(v.rbegin(), v.rend());
    
    for(auto [h, k] : v){
        auto it = teams.upper_bound(k-1);
        if (it != teams.begin()){
            --it;
            int val = *it;    
            teams.erase(it); 
            teams.insert(val+1);
        }
        else{
            teams.insert(1);
        }
    }
    
    cout << teams.size();
}