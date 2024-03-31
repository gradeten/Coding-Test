#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    int cnt = 0;
    
    for(int i = 0; i < s.size(); i++){
        if (isblank(s[i])){
            answer += (s[i]);
            cnt = 0;
        }
        else{
            if (cnt % 2 == 0){
                answer += toupper(s[i]);
                cnt++;
            }
            else
            {
                answer += tolower(s[i]);
                cnt++;
            }
        }
    }
    return answer;
}