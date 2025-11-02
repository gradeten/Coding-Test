#include <bits/stdc++.h>
using namespace std;

bool solve(string s){
    stack<char> st;
    for(int i = 0; i < s.size(); i++){
        if (s[i] == '[' || s[i] == '(' || s[i] == '{'){
            st.push(s[i]);
        }
        else{
            if (s[i] == ']'){
                if (st.top() == '[') st.pop();
                else return false;
            }
            else if (s[i] == ')'){
                if (st.top() == '(') st.pop();
                else return false;
            }
            else if (s[i] == '}'){
                if (st.top() == '{') st.pop();
                else return false;
            }
        }
    }
    if (st.empty()) return true;
    else return false;
}

int solution(string s) {
    int answer = 0;
    
    for(int i = 0; i < s.size(); i++){
        // cout << s << '\n';
        if (solve(s)) answer++;
        s += s[0];
        s.erase(0,1);
    }
    
    return answer;
}