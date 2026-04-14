#include <bits/stdc++.h>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    int a = 0; int b = 0;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    for(int i = 0; i < s.length(); i++){
        if (s[i] == 'p') a++;
        else if (s[i] == 'y') b++;
    }
    if (a != b) answer = false;

    return answer;
}