#include <bits/stdc++.h>
using namespace std;
int n;
int original[1000005];
vector<int> arr, num;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> original[i];
        arr.push_back(original[i]);
    }
    sort(arr.begin(), arr.end());
    
    num.push_back(arr[0]);
    for(int i = 0; i < n; i++){
        if (i != 0 && arr[i] != arr[i-1]) num.push_back(arr[i]);
    }
    
    for(int i = 0; i < n; i++){
        cout << lower_bound(num.begin(), num.end(), original[i]) - num.begin() << ' ';
    }
}