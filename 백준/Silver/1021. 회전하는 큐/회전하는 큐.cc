#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    deque<int> DQ;
    int ans = 0;
    
    int N, M;
    cin >> N >> M;
    
    for(int i = 1; i <= N; i++) DQ.push_back(i);
    
    while(M--)
    {
        int a;
        cin >> a;
        
        if (DQ.front() == a || DQ.size() == 1) DQ.pop_front();
        else
        {
            int index = 0;
            for(int i = 0; i < N; i++)
            {
                if(DQ[i] == a) 
                {
                    index = i+1;
                    break;
                }
            }
            
            if (index <= (DQ.size()/2+1))
            {
                while(DQ.front() != a)
                {
                    DQ.push_back(DQ.front());
                    DQ.pop_front();
                    ans++;
                }
                DQ.pop_front();
            }
            else
            {
                while(DQ.front() != a)
                {
                    DQ.push_front(DQ.back());
                    DQ.pop_back();
                    ans++;
                }
                DQ.pop_front();
            }
        }
        
    }
    cout << ans;
}