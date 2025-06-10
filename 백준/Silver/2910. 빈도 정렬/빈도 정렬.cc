#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, c;
    cin >> n >> c;
    
    unordered_map<int,int> freq;
    unordered_map<int,int> first;
    vector<int> input(n);
    
    for(int i = 0; i < n; i++){
        cin >> input[i];
        freq[input[i]]++;
        if (first.find(input[i]) == first.end()){
            first[input[i]] = i;
        }
    }
    
    sort(input.begin(), input.end(), [&](int a,int b){
    if (freq[a] != freq[b]) return freq[a] > freq[b];
    return first[a] < first[b];
    });
    
    for(auto i : input) cout << i << " ";
}