#include <bits/stdc++.h>
using namespace std;

int A[101][101]; // Change to 1-indexed for easier matching with problem
int r = 3, c = 3;
int now = 0;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second) 
    {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int R, C, K;
    cin >> R >> C >> K;
    
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> A[i][j];
        }
    }
    
    while(now <= 100){
        
        if (A[R][C] == K) {
            cout << now;
            return 0;
        }
        
        int new_r = r; // Initialize new_r and new_c
        int new_c = c;
  
        if (r >= c){ // 행 연산
            for(int i = 1; i <= r; i++){
               map <int,int> countMap;
               
               for(int j = 1; j <= c; j++){
                   if (A[i][j] == 0) continue;
                   countMap[A[i][j]]++;
               }
            
                vector<pair<int,int>> v;
                for(auto& p: countMap){
                    v.push_back({p.first, p.second});
                }
                
                sort(v.begin(), v.end(), compare);
                
                // Clear the current row
                for(int j = 1; j <= 100; j++) {
                    A[i][j] = 0;
                }
                
                int index = 1;
                for(auto& p: v){
                    A[i][index++] = p.first;
                    if (index > 100) break;
                    A[i][index++] = p.second;
                    if (index > 100) break;
                }
                
                new_c = max(new_c, index - 1);
            }
            c = new_c;
        }
        else{ // 열 연산
           for(int i = 1; i <= c; i++){
               map <int,int> countMap;
               
               for(int j = 1; j <= r; j++){
                   if (A[j][i] == 0) continue;
                   countMap[A[j][i]]++;
               }
            
                vector<pair<int,int>> v;
                for(auto& p: countMap){
                    v.push_back({p.first, p.second});
                }
                
                sort(v.begin(), v.end(), compare);
                
                // Clear the current column
                for(int j = 1; j <= 100; j++) {
                    A[j][i] = 0;
                }
                
                int index = 1;
                for(auto& p: v){
                    A[index++][i] = p.first;
                    if (index > 100) break;
                    A[index++][i] = p.second;
                    if (index > 100) break;
                }
                
                new_r = max(new_r, index - 1);
            }
            r = new_r;
        }
        
        now++;
    }
    
    cout << -1;
    return 0;
}