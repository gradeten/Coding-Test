#include <bits/stdc++.h>
using namespace std;
vector<int> arr;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b;
    cin >> a >> b;
    
    int i = 1;
    while(arr.size() < 1000){
        for(int j = 0; j < i; j++){
            arr.push_back(i);
        }
        i++;
    }
    
    long long ans = 0;
    for(int i = a-1; i <= b-1; i++){
        ans += arr[i];
    }
    cout << ans;
}