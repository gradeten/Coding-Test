#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, p, prob, diff, x;
    
    cin >> n;
    set<pair<int,int>> s;
    map<int,int> mp;
    for(int i = 0; i < n; i++){
        cin >> prob >> diff;
        s.insert({diff, prob});
        mp[prob] = diff;
    }
    
    cin >> p;
    while(p--){
        string com;
        cin >> com;
        if (com == "add"){
            cin >> prob >> diff;
            s.insert({diff, prob});
            mp[prob] = diff;
        }
        else if (com == "recommend"){
            cin >> x;
            if (x == 1) cout << s.rbegin()->second << '\n';
            else cout << s.begin()->second << '\n';
        }
        else if (com == "solved"){
            cin >> prob;
            int d = mp[prob];
            s.erase({d, prob});
            mp.erase(prob);
        }
    }
}