#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num[5], sum;
    
    for(int i = 0; i < 5; i++) cin >> num[i];
    for(int i = 0; i < 5; i++) sum += num[i];
    sort(num, num + 5);
    
    cout << sum/5 << "\n" << num[2];
}
