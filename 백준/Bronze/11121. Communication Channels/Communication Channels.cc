#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while(T--){
        string input, output;
        cin >> input >> output;
        if (input == output) cout << "OK";
        else cout << "ERROR";
        cout << '\n';
    }
}