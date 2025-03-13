#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string jinho;
    int N;
    cin >> jinho >> N;
    
    int answer = 0;
    
    while(N--){
        string s;
        cin >> s;
        if (s == jinho) answer++;
    }
    
    cout << answer;
}