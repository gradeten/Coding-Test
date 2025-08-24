#include <bits/stdc++.h>
using namespace std;
int n, p, m, l, g, x;
set<pair<int,int>> allSet; // l, p
set<pair<int,int>> groupSet[105]; // l, p
pair<int,int> problem[100005]; // l, g

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p >> l >> g;
        allSet.insert({l,p});
        groupSet[g].insert({l,p});
        problem[p] = make_pair(l, g);
    }
    
    cin >> m;
    while(m--){
        string com; cin >> com;
        if(com == "add"){
            cin >> p >> l >> g;
            allSet.insert({l,p});
            groupSet[g].insert({l,p});
            problem[p] = make_pair(l, g);
        }
        else if (com == "recommend"){
            cin >> g >> x;
            if (x == 1){
                cout << groupSet[g].rbegin()->second << '\n';
            }
            else if (x == -1){
                cout << groupSet[g].begin()->second << '\n';
            }
        }
        else if (com == "recommend2"){
            cin >> x;
            if (x == 1){
                cout << allSet.rbegin()->second << '\n';
            }
            else if (x == -1){
                cout << allSet.begin()->second << '\n';
            }
        }
        else if (com == "recommend3"){
            cin >> x >> l;
            if (x == 1){
                auto it = allSet.lower_bound({l, 0});   
                if (it == allSet.end()) cout << -1 << '\n';
                else cout << it->second << '\n';
            } else { 
                auto it = allSet.lower_bound({l, 0});   
                if (it == allSet.begin()) cout << -1 << '\n'; 
                else {
                    --it;                               
                    cout << it->second << '\n';
                }
            }
        }
        else if (com == "solved"){
            cin >> p;
            int l = problem[p].first;
            int g = problem[p].second;
            allSet.erase({l,p});
            groupSet[g].erase({l,p});
        }
    }
}