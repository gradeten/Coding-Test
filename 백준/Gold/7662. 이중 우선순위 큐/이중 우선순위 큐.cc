#include <bits/stdc++.h>
using namespace std;
int t, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--){
        cin >> k;
        multiset<int> ms;
        while(k--){
            char c; int i;
            cin >> c >> i;
            if (c == 'I') ms.insert(i);
            else if (c == 'D'){
                if (ms.empty()) continue;
                if (i == 1) ms.erase(prev(ms.end()));
                else if (i == -1) ms.erase(ms.begin());
            }
        }
        if (ms.empty()) cout << "EMPTY\n";
        else cout << *prev(ms.end()) << ' '<< *ms.begin() << '\n';
    }
}