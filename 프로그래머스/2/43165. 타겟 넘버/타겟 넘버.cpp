#include <bits/stdc++.h>
using namespace std;
int ans = 0;

void dfs(int sum, int depth, vector<int> numbers, int target){
    if (depth == numbers.size()){
        if (sum == target) ans++;
        return;
    }
    dfs(sum-numbers[depth], depth+1, numbers, target);
    dfs(sum+numbers[depth], depth+1, numbers, target);
}

int solution(vector<int> numbers, int target) {
    
    dfs(0,0,numbers,target);
    
    return ans;
}