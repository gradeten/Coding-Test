#include <string>
#include <vector>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    for(int i = 0; i < privacies.size(); i++){
        for(int j = 0; j < terms.size(); j++){
            if (privacies[i][11] == terms[j][0]){
                
                int l = stoi(terms[j].substr(2));
                
                int y = stoi(privacies[i].substr(0,4));
                int m = stoi(privacies[i].substr(5,2));
                int d = stoi(privacies[i].substr(8,2));
                
            
                int t_y = stoi(today.substr(0,4));
                int t_m = stoi(today.substr(5,2));
                int t_d = stoi(today.substr(8,2));
                
                if ((y*28*12 + m*28 + d + l*28) <= (t_y*28*12 + t_m*28 + t_d)){
                    answer.push_back(i+1);
                }
               
                
                
                break;
            }
        }
    }
    
    return answer;
}