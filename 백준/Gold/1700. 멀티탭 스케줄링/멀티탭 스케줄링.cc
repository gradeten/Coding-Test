#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    int ans = 0;
    
    cin >> n >> k;
    vector<int> tab;
    vector<int> item(k);
    for(int i = 0; i < k; i++)  cin >> item[i];
    
    for(int i = 0; i < k; i++){
        if (find(tab.begin(), tab.end(), item[i]) == tab.end()){ // 멀티탭에 있는지
            if (tab.size() == n){ // 멀티탭 꽉 참
                int mx = -1; int d = -1;
                for(int j = 0; j < n; j++){
                    int idx = 1e9;
                    for(int l = i+1; l < k; l++){
                        if (item[l] == tab[j]){
                            idx = l; 
                            break;
                        }
                    }
                    if (idx > mx){
                        mx = idx;
                        d = j;
                    }
                }
                
                tab[d] = item[i];
                ans++;
                
            }
            else{ // 멀티탭 빈칸 있음
                tab.push_back(item[i]);
            }
        }
    }
    
    cout << ans;
}