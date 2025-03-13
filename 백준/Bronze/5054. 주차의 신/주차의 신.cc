#include <bits/stdc++.h>
using namespace std;
int arr[100];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while(T--){
        int num;
        cin >> num;
        int sum = 0;
        for(int i = 0; i < num; i++) cin >> arr[i];
        sort(arr,arr+num);
        cout << abs(arr[0] - arr[num-1]) * 2;
        cout << '\n';
    }
}