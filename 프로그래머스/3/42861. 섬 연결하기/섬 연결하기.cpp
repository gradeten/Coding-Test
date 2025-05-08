#include <bits/stdc++.h>
using namespace std;

int parent[101];

int find (int x){
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int solution(int n, vector<vector<int>> costs) {
    for(int i = 0; i < n; i++) parent[i] = i;
    
    sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b){
        return a[2] < b[2];
    });
    
    
    int answer = 0;
    for(auto& edge : costs){
        int a = edge[0];
        int b = edge[1];
        int cost = edge[2];
        
        if (find(a) != find(b)){
            unite(a,b);
            answer += cost;
        }
    }
    
    return answer;
}