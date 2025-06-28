#include <bits/stdc++.h>
using namespace std;

int calc(string expr){
    int sum = 0;
    stringstream ss(expr);
    string token;
    while(getline(ss, token, '+')){
        sum += stoi(token);
    }
    return sum;
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    vector<string> parts;
    stringstream ss(s);
    string token;
    
    while(getline(ss, token, '-')){
        parts.push_back(token);
    }
    
    int result = calc(parts[0]);
    
    for(int i = 1; i < parts.size(); i++){
        result -= calc(parts[i]);
    }
    
    cout << result;
    return 0;
}