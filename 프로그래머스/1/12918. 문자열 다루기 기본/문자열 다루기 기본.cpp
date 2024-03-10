#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

bool solution(string s) {
    for(int i = 0; i < s.size(); i++){
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    
    if ((s.size() == 4) || (s.size() == 6)){
        return true;
    }
    else{
        return false;
    }
}