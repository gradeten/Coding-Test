#include <bits/stdc++.h>
using namespace std;
int a[500005];

int lower_index(int target, int len){
    int st = 0;
    int en = len;
    while(st < en){
        int mid = (st+en)/2;
        if (a[mid] >= target) en = mid;
        else st = mid + 1;
    }
    return st;
}

int upper_index(int target, int len){
    int st = 0;
    int en = len;
    while(st < en){
        int mid = (st+en)/2;
        if (a[mid] > target) en = mid;
        else st = mid + 1;
    }
    return st;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n;
    
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);
    
    cin >> m;
    for(int i = 0; i < m; i++){
        int tar; cin >> tar;
        cout << upper_index(tar, n) - lower_index(tar, n) << " ";
    }
}