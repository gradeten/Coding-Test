#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    if (!arr.empty()) answer.push_back(arr[0]);

    for(int i = 1; i < arr.size(); i++){
        if (arr[i-1] != arr[i]){
            answer.push_back(arr[i]);
        }
    }
    
    return answer;
}