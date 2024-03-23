#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    sort(X.begin(), X.end(), greater<int>());
    sort(Y.begin(), Y.end(), greater<int>());
    
    int a = 0;
    int b = 0;
    while((a < X.length()) && (b < Y.length())){
        if (X[a] == Y[b]){
            answer += X[a];
            a++;
            b++;
        }
        else if (X[a] > Y[b]){
            a++;
        }
        else if (X[a] < Y[b]){
            b++;
        }
    }
    
    if(answer == ""){
        return "-1";
    }
    else if (answer[0] == '0'){
        return "0";
    }
    else{
        return answer;
    }
}