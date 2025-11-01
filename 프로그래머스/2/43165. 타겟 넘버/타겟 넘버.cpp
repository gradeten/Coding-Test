#include <bits/stdc++.h>
using namespace std;

int ans = 0;

void func(int sum, int depth, vector<int> numbers, int target){
    if (depth == numbers.size()){
        if (sum == target) ans++;
        return;
    }
  
    func(sum-numbers[depth],depth+1,numbers,target);
    func(sum+numbers[depth],depth+1,numbers,target);
}

int solution(vector<int> numbers, int target) {
    func(0,0,numbers,target);
    return ans;
}