#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[10];
int ans[10];
bool isused[10];

void func(int k){
    if (k == m){
        for(int i = 0; i < m; i++) cout << arr[ans[i]] << ' ';
        cout << '\n';
        return;
    }

    int st = 0;
    if(k != 0) st = ans[k-1] + 1;
    
    int prev = -1;
    
    for(int i = st; i < n; i++){
        if (!isused[i] && arr[i] != prev){
            isused[i] = 1;
            ans[k] = i;
            func(k+1);
            isused[i] = 0;
            prev = arr[i];
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    
    func(0);
}