#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int card[20];
    int start, end;
    
    for(int i = 0; i < 20; i++) card[i] = i + 1;
    
    for(int i = 0; i < 10; i++)
    {
        cin >> start >> end;
        reverse(card + start-1, card + end);
    }
    
    for(int i = 0; i < 20; i++) cout << card[i] << " ";
    
}