#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    int arr[n+1];
    int d[n+1];

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    
    d[0] = 0;
    d[1] = arr[1];
    for(int i = 2; i <= n; i++){
        d[i] = d[i-1] + arr[i];
    }
    
    while(m--){
        int start, end;
        cin >> start >> end;
        cout << d[end] - d[start-1] << "\n";
    }
}