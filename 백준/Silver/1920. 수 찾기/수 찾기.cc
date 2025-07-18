#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100005];

int find_num(int target){
    int st = 0; int en = n-1;
    while(st <= en){
        int mid = (st+en)/2;
        if (target == a[mid]) return 1;
        else if (target < a[mid])  en = mid - 1;
        else if (target > a[mid]) st = mid + 1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);
    
    cin >> m;
    while(m--){
        int num;
        cin >> num;
        cout << find_num(num) << '\n';
    }
}