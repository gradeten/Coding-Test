#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    stack<int> S;
    int num[N];
    int answer[N] = {0};
    
    for(int i = 0; i < N; i++) cin >> num[i];

    for(int i = 0; i < N; i++)
    {
        while(!S.empty() && num[S.top()] <= num[i]) S.pop();
        
        if(!S.empty()) answer[i] = S.top() + 1;

        S.push(i);
    }
    
    for(int i = 0; i < N; i++) cout << answer[i] << " ";
}