#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    set<int> s;

    for (int i = 0; i < n; i++) {   
        int a; cin >> a;
        if (a == 1) s.insert(i);
    }

    int now = 0;   

    while (q--) {
        int com;
        cin >> com;

        if (com == 1) {
            int i; cin >> i;
            i--;  
            if (s.find(i) == s.end()) s.insert(i);
            else s.erase(i);
        }
        else if (com == 2) {
            int x; cin >> x;
            now = (now + x) % n;   
        }
        else if (com == 3) {
            if (s.empty()) {
                cout << -1 << '\n';
            } else {
                auto it = s.lower_bound(now);
                if (it == s.end()) it = s.begin();  
                int diff = (*it - now + n) % n;     
                cout << diff << '\n';
            }
        }
    }
}
