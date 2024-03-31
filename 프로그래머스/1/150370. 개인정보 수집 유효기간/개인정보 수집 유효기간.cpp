#include <string>
#include <vector>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    for(int i = 0; i < privacies.size(); i++){
        for(int j = 0; j < terms.size(); j++){
            if (privacies[i][11] == terms[j][0]){
                
                int l = stoi(terms[j].substr(2));
                vector<string> date(3);
                int cnt = 0;
                
                for(int k = 0; k < 10; k++){
                    if (privacies[i][k] != '.'){
                        date[cnt] += privacies[i][k];
                    }
                    else{
                        cnt++;
                    }
                }
                if (date[1][0] == '0'){
                    date[1].erase(0,1);
                }
                if (date[2][0] == '0'){
                    date[2].erase(0,1);
                }
                
                int y = stoi(date[0]);
                int m = stoi(date[1]);
                int d = stoi(date[2]);
                
                vector<string> t(3);
                cnt = 0;
                
                for(int k = 0; k < 10; k++){
                    if (today[k] != '.'){
                        t[cnt] += today[k];
                    }
                    else{
                        cnt++;
                    }
                }
                if (t[1][0] == '0'){
                    t[1].erase(0,1);
                }
                if (t[2][0] == '0'){
                    t[2].erase(0,1);
                }
                
                int t_y = stoi(t[0]);
                int t_m = stoi(t[1]);
                int t_d = stoi(t[2]);
                
                if ((y*28*12 + m*28 + d + l*28) <= (t_y*28*12 + t_m*28 + t_d)){
                    answer.push_back(i+1);
                }
               
                
                
                break;
            }
        }
    }
    
    return answer;
}