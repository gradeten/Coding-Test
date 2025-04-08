#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string vowel1 = "aeiou";
    string vowel2 = "aeiouy";
    
    string s;
    cin >> s;
    
    int sum1 = 0;
    int sum2 = 0;
    
    for(char c : s){
        if (vowel1.find(c) != string::npos) sum1++;
    }
    
    for(char c : s){
        if (vowel2.find(c) != string::npos) sum2++;
    }
    
    cout << sum1 << ' ' << sum2;
    
}