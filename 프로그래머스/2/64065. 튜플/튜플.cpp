#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(string s) {
    vector<vector<int>> sets;
    
    s = s.substr(2,s.length() - 4);
    
    size_t pos = 0;
    while ((pos = s.find("},{")) != string::npos){
        string token = s.substr(0,pos);
        stringstream ss(token);
        string num;
        vector<int> temp;
        while (getline(ss, num, ',')){
            temp.push_back(stoi(num));
        }
        sets.push_back(temp);
        s = s.substr(pos + 3);
    }
    
    stringstream ss(s);
    string num;
    vector<int> temp;
    while(getline(ss, num, ',')){
        temp.push_back(stoi(num));
    }
    sets.push_back(temp);
    
    sort(sets.begin(), sets.end(), [](vector<int> & a, vector<int> & b){
        return a.size() < b.size();
    });
    
    vector<int> answer;
    set<int> seen;
    for (auto& vec : sets){
        for (int n : vec){
            if (seen.find(n) == seen.end()){
                answer.push_back(n);
                seen.insert(n);
                break;
            }
        }
    }
    
    return answer;
}