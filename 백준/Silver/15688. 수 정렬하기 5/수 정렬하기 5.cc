#include <bits/stdc++.h>
using namespace std;
int freq[20000001] = {0};

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if (a < 0){freq[a*(-1)+1000000]++;}
        else{freq[a]++;}
    }
    
    for(int i = 2000000; i > 1000000; i--){
        if (freq[i] > 0){
            for(int j = 0; j < freq[i]; j++){
                cout << (i-1000000)*(-1) << "\n";
            }
        }
    }
    for(int i = 0; i <= 1000000; i++){
        if (freq[i] > 0){
            for(int j = 0; j < freq[i]; j++){
                cout << i << "\n";
            }
        }
    }
}