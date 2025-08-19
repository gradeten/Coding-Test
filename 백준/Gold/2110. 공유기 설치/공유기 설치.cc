#include <bits/stdc++.h>
using namespace std;
int n, c;
int x[200005];

bool solve(int d){
    int cnt = 1;
    int last = x[0];
    
    for(int i = 1; i < n; i++){
        if (x[i] - last >= d){
            cnt++;
            last = x[i];
        } 
    }
    return cnt >= c;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> c;
    for(int i = 0; i < n; i++) cin >> x[i];
    sort(x,x+n);
    
    int st = 1;
int en = x[n-1] - x[0];
int ans = 0;

while (st <= en) {
    int mid = (st + en) / 2;   // 일반적인 중간값
    if (solve(mid)) {
        ans = mid;             // 가능한 값 저장
        st = mid + 1;          // 더 큰 거리 시도
    } else {
        en = mid - 1;          // 줄이기
    }
}
cout << ans;
    
}