#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    int card[500005];
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> card[i];
    sort(card,card+n);
    
    cin >> m;
    while(m--){
        int num;
        cin >> num;
        cout << binary_search(card,card+n,num) << ' ';
    }
}