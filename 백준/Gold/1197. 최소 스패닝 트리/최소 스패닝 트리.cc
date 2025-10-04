// lecture code
#include <bits/stdc++.h>
using namespace std;

vector<int> p(10005, -1); // Union-Find용 배열. 음수값은 집합의 크기, 양수는 부모 노드 인덱스를 가리킴.

int find(int x){ // x가 속한 그룹의 root 찾기
    if (p[x] < 0) return x;
    return p[x] = find(p[x]); // 경로 압축 기법
}

bool is_diff_group(int u, int v){ // 두 노드를 합치는 함수 (더 큰 집합에 작은 집합을 합친다)
    u = find(u); v = find(v);
    if (u == v) return 0; // 같은 그룹이면 사이클 생기므로 합칠 필요 없음
    
    if(p[u] == p[v]) p[u]--; // 두 그룹 크기 같다면 u 그룹 크기 증가
    if(p[u] < p[v]) p[v] = u; // u 그룹이 더 크면 v를 u에 붙임
    else p[u] = v; // v 그룹이 더 크면 u를 v에 붙임
    return 1;
}

int v, e;
tuple<int, int, int> edge[100005]; // 비용, 시작, 끝

int main(){ // 
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> v >> e;
    for(int i = 0; i < e; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = {cost, a, b};
    }
    sort(edge, edge + e);
    
    // 크루스칼 알고리즘 구현
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < e; i++){
        int a, b, cost;
        tie(cost, a, b) = edge[i]; // edge에서 하나 꺼냄
        if (!is_diff_group(a, b)) continue; // 같은 그룹이면 패스
        ans += cost; // 다른 그룹이면 선택 -> 비용 추가
        cnt++; // 간선 개수 증가
        if (cnt == v - 1) break; // MST 완성 (정점-1개의 간선으로 연결됨)
    }
    cout << ans;
}