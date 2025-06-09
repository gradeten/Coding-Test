#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    vector<long long> ans;
    long long cnt = 0;
    string s;

    while (cnt < n && cin >> s) {
        reverse(s.begin(), s.end());
        ans.push_back(stoll(s));
        cnt++;
    }

    sort(ans.begin(), ans.end());

    for (auto i : ans) {
        cout << i << "\n";
    }
}
