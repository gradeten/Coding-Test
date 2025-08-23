#include <bits/stdc++.h>
using namespace std;
int n, q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> q;
    set<int> s;
    for(int i = 1; i <= n; i++){
        int a; cin >> a;
        if (a == 1) s.insert(i);
    }
    int now = 1;
    
    while(q--){
        int com, i, x;
        cin >> com;
        if (com == 1){
            cin >> i;
            if (s.find(i) == s.end()) s.insert(i);
            else s.erase(i);
        }
        else if (com == 2){
            cin >> x;
            now = (now - 1 + n + x) % n + 1;
        }
        else if (com == 3){
            if (s.empty()) cout << -1 << '\n';
            else{
                auto it = s.lower_bound(now);
                if (it == s.end()) it = s.begin();  // end면 맨 앞으로 순환
                int diff = *it - now;
                if (diff < 0) diff += n;
                cout << diff << '\n';
            }
        }
    }
}