#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while(T--){
        int num;
        cin >> num;
        
        vector<int> student(num+1);
        vector<bool> vis(num+1, false);
        vector<bool> team(num+1, false);
        
        for(int i = 1; i <= num; i++)  cin >> student[i];

        
        for(int i = 1; i <= num; i++){
             if (vis[i]) continue;
             
             vector<int> path;
             int cur = i;
             
             while(!vis[cur]){
                 vis[cur] = true;
                 path.push_back(cur);
                 cur = student[cur];
             }
             
             for (int p : path){
                 if (p == cur){
                     for(int x : path) {
                        if(x == cur) {  
                            team[x] = true; 
                        }
                        else if(team[cur]) {  
                            team[x] = true; 
                        }
                    }
                 }
             }
        }
        
        int answer = 0;
        for(int i = 1; i <= num; i++) {
            if(!team[i]) answer++;
        }
        
        cout << answer << '\n';
    }
}