#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> num;
vector<int> op(4);
int min_result = INT_MAX;
int max_result = INT_MIN;

void dfs(int idx, int result){
    if (idx == n){
        min_result = min(min_result, result);
        max_result = max(max_result, result);
        return;
    }
    for(int i = 0; i < 4; i++){
        if (op[i] > 0){
            op[i]--;
            int next_result = result;
            if (i == 0) next_result += num[idx];
            else if (i == 1) next_result -= num[idx];
            else if (i == 2) next_result *= num[idx];
            else if (i == 3){
                if (next_result < 0)
                    next_result = -(-next_result / num[idx]);
                else
                    next_result /= num[idx];
            }
            dfs(idx+1, next_result);
            op[i]++;
        }
    }
}

int main (void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    num.resize(n);
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    for(int i = 0; i < 4; i++){
        cin >> op[i];
    }
    dfs(1,num[0]);
    cout << max_result << "\n" << min_result;
}