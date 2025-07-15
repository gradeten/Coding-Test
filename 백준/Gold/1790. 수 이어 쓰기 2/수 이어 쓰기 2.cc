#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    long long length = 0;
    int c = 1, temp = n;
    while (temp /= 10) c++;  // 자릿수 구하기

    for(int i = 1; i < c; i++){
        length += 1LL * i * 9 * pow(10, i - 1);
    }
    for(int i = pow(10, c - 1); i <= n; i++){
        length += to_string(i).size(); // 정확한 길이
    }

    if (length < k){
        cout << -1;
        return 0;
    }

    // 자릿수별로 어느 그룹에 속하는지 찾기
    int cnt = 1;
    long long digit_len = 9;

    while (k - digit_len * cnt > 0){
        k -= digit_len * cnt;
        digit_len *= 10;
        cnt++;
    }

    int offset = (k - 1) / cnt;
    int index = (k - 1) % cnt;

    int a = pow(10, cnt - 1) + offset;
    string s = to_string(a);
    cout << s[index] << '\n';
}
