#include <bits/stdc++.h>
using namespace std;
vector<long long> numbers;

void dfs(long long num){
    numbers.push_back(num);
    int lastDigit = num % 10;
    for(int i = 0; i < lastDigit; i++){
        dfs(num * 10 + i);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    
    for(int i = 0; i <= 9; i++){
        dfs(i);
    }
    
    sort(numbers.begin(), numbers.end());
    
    if (n >= numbers.size()) cout << -1;
    else cout << numbers[n];
}