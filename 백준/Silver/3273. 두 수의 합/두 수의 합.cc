#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num[1000001] = {0};
    int n, sum;
    int answer = 0;
    cin >> n;
    
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> sum;
    
    for(int i = 0; i < n; i++)
    {
        if(sum-a[i] >= 0 && sum-a[i] <= 1000000 && num[sum-a[i]] == 1) answer++;
        num[a[i]] = 1;
    }
    
    cout << answer;
}