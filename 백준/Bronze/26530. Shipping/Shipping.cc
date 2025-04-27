#include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while(t--){
        int items;
        cin >> items;
        float sum = 0;
        
        while(items--){
            string name;
            float quantity, price;
            cin >> name >> quantity >> price;
            sum += quantity * price;
        }
        cout << "$" << fixed << setprecision(2) << sum << "\n";
       
    }
    
    return 0;
}