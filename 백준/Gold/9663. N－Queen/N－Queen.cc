#include <bits/stdc++.h>
using namespace std;
int n;
int cnt = 0;

bool isused1[40];
bool isused2[40];
bool isused3[40];


void func(int row){
    if (row == n){
        cnt++;
        return;
    }
    for(int col = 0; col < n; col++){
        if (isused1[col] || isused2[row+col] || isused3[row-col+n-1]) continue;
        
        isused1[col] = true;
        isused2[row+col] = true;
        isused3[row-col+n-1] = true;
        
        func(row+1);
        
        isused1[col] = false;
        isused2[row+col] = false;
        isused3[row-col+n-1] = false;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    func(0);
    
    cout << cnt;
}