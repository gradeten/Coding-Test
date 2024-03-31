#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    if (s[0] == '-'){
        s.erase(0,1);
        return (0-stoi(s));
    }
    else{
        return stoi(s);
    }

}