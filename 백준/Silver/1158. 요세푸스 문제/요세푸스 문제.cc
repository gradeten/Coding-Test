#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;
    
    list<int> L;
    for(int i = 0; i < N; i++) L.push_back(i+1);
    auto cursor = L.begin();
    advance(cursor, K - 1);
    
    cout << "<";
    while (L.size() > 1)
    {
        cout << *cursor << ", ";
        cursor = L.erase(cursor);
        
        if (cursor == L.end()) cursor = L.begin();
        for (int i = 0; i < K - 1; i++) {
            cursor++;
            if (cursor == L.end()) cursor = L.begin();
        }
    }
    cout << *L.begin() << ">\n";
}