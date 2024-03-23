#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    for(int i = 0; i < s.size(); i++){
        int j = 1;
        char c = s[i];
        while(j <= index){
            if (c == 'z'){
                c = 'a';
            }
            else{
                c = ((c-'0')+1) + '0';
            }
            if (skip.find(c) == ::string::npos){
                j++;
            }
        }
        answer += c;
    }
    
    return answer;
}