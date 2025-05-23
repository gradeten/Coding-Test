#include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, w, l;
    cin >> n >> w >> l;
   
    queue<int> trucks;
    for(int i = 0; i < n; i++){
        int weight;
        cin >> weight;
        trucks.push(weight);
    }
    
    queue<int> bridge;
    int time = 0;
    int bridge_weight = 0;
    
    for(int i = 0; i < w; ++i) bridge.push(0);
    
    while(!trucks.empty() || bridge_weight > 0){
        time++;
        
        bridge_weight -= bridge.front();
        bridge.pop();
        
        if (!trucks.empty()){
            if (bridge_weight + trucks.front() <= l){
                int t = trucks.front(); trucks.pop();
                bridge.push(t);
                bridge_weight += t;
            }
            else{
                bridge.push(0);
            }
        }
        else{
            bridge.push(0);
        }
    }
    
    cout << time;
}