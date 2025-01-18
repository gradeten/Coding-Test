#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string N;
    int num[10] = {0};
    cin >> N;
    
    for(int i = 0; i < N.size(); i++)  num[N[i]-'0']++;
    
    int six_nine_sum = num[6] + num[9];
    num[6] = (six_nine_sum+1)/2;
    num[9] = 0;
    
    int max = *max_element(num, num + 10);
    cout << max;

}