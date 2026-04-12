#include <bits/stdc++.h>
using namespace std;

bool solution(string s)
{
    stack<char> st;
    for(int i = 0; i < s.length(); i++){
        if (s[i] == '('){
            st.push(s[i]);
        }
        else{
            if (st.empty()) return false;
            else if (st.top() == '(') st.pop();
        }
    }

    return st.empty();
}