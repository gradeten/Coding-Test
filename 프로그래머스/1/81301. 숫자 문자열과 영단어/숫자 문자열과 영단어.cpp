#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    
    vector<string> v1 = 
    {"zero","one","two","three","four","five","six","seven","eight", "nine"};
    vector<string> v2 = {"0","1","2","3","4","5","6","7","8","9"};
    
    for(int i = 0; i < 10; i++){
        size_t pos = 0;
        while((pos = s.find(v1[i], pos)) != string::npos){
            s.replace(pos,v1[i].length(), v2[i]);
            pos += v2[i].length();
        }
    }
    return stoi(s);
}