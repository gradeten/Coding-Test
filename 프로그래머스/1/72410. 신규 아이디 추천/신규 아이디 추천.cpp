#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string answer = new_id;
    // 1단계
    for(int i = 0; i < new_id.size();i++){
        if (new_id[i] <= 'Z' && new_id[i] >= 'A'){
            new_id[i] += 32;
        }
    }
    // 2단계
    string s = "";
    for(int i = 0; i < new_id.size();i++){
        if ((new_id[i] >= 'A' && new_id[i] <= 'Z')||
            (new_id[i] >= 'a' && new_id[i] <= 'z')||
            (new_id[i] >= '0' && new_id[i] <= '9')||
            (new_id[i] == '-')||(new_id[i] == '_')||(new_id[i] == '.')
           )
        {
            s += new_id[i];
        }
    }
    new_id = s;
    
    // 3단계
    s = "";
    for(int i = 0; i < new_id.size(); i++){
        if (s.size() == 0){
            s += new_id[i];
        }
        else{
            if (new_id[i] == '.'){
                if (s[s.size()-1] != '.'){
                    s += new_id[i];
                }
            }
            else s += new_id[i];
        }
    }
    new_id = s;
    
    // 4단계
    if (new_id[0] == '.') new_id.erase(0,1);
    if (new_id[new_id.size()-1] == '.') new_id.erase(new_id.size()-1,1);
    
    // 5단계
    if (new_id == ""){
        new_id += 'a';
    }
    
    // 6단계
    if (new_id.size() >= 16){
        new_id.erase(15, new_id.size() - 15);
        if (new_id[new_id.size()-1] == '.') new_id.erase(new_id.size()-1,1);
    }
    
    // 7단계
    if (new_id.size() <= 2){
        char c = new_id[new_id.size()-1];
        while(new_id.size() != 3){
            new_id += c;
        }
    }
    
    return new_id;
}