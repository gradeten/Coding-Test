#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min;
    
    if (arr.size() == 1)
    {
        answer.push_back(-1);
    }
    else
    {
        answer = arr;
        sort(arr.begin(), arr.end());
        min = arr[0];
        answer.erase(remove(answer.begin(), answer.end(), min), answer.end());
    }
    
    return answer;
}