#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while(T--){
        int score;
        cin >> score;
        for(int i = 0; i < score / 5; i++){
            cout << "++++ ";
        }
        for(int i = 0; i < score % 5; i++){
            cout << "|";
        }
        cout << '\n';
    }
}