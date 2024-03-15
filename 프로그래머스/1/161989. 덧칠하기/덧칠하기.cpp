#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int current = 0;
    
    for(int i = 0; i < section.size(); i++){
        if (current > section[i]){
            continue;
        }
        answer++;
        current = section[i] + m;
    }
    
    return answer;
}