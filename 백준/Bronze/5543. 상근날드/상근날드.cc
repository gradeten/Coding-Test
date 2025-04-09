#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int burger1, burger2, burger3;
    int soda1, soda2;
    
    int burger = 3000;
    int soda = 3000;
    
    cin >> burger1 >> burger2 >> burger3 >> soda1 >> soda2;
    burger = min(min(burger1, burger2), burger3);
    soda = min(soda1, soda2);
    
    cout << burger + soda - 50;
}