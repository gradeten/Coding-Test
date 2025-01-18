#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int arr[26] = {0};
    string s;
    cin >> s;
    
    for(int i = 0; i < s.size(); i++)
    {
        int a = s[i]-97;
        arr[a]++;
    }
    
    for(int i = 0; i < 26; i++)
    {
        cout << arr[i] << " ";
    }
}