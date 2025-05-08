#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b){
    string x = to_string(a);
    string y = to_string(b);
    
    return x + y > y + x;
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), cmp);
    
    if (numbers[0] == 0) return "0";
    for (int i = 0; i < numbers.size(); i++){
        answer += to_string(numbers[i]);
    }
    
    return answer;
}