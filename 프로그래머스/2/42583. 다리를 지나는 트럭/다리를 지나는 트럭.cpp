#include <bits/stdc++.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    int bridge_weight = 0;
    queue<int> bridge;
    queue<int> trucks;
    for(int i = 0; i < truck_weights.size(); i++){
        trucks.push(truck_weights[i]);
    }
    for(int i = 0; i < bridge_length; i++){
        bridge.push(0);
    }
    
    while(!trucks.empty() || bridge_weight != 0){
        time++;
        
        bridge_weight -= bridge.front();
        bridge.pop();
        
        if (!trucks.empty()){
            if (bridge_weight + trucks.front() <= weight){
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
    
    
    return time;
}