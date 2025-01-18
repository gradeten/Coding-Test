#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num[10] = {0};
    int A, B, C;
    cin >> A >> B >> C;
    
    string s = to_string(A * B * C);
    for(int i = 0; i < s.size(); i++) num[s[i]-'0']++;
    for(int i = 0; i < 10; i++) cout << num[i] << " ";
    
}