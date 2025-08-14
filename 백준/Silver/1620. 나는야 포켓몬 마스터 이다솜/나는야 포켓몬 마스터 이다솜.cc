#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    string names1[100000];
    unordered_map<string,int> names2;
    
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        names1[i] = s;
        names2[s] = i;
    }
    
    while(m--){
        string s; cin >> s;
        if (isdigit(s[0])){
            cout << names1[stoi(s)] << '\n';
        }
        else{
            cout << names2[s] << '\n';
        }
    }
}