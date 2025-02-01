#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while(T--)
    {
        string command;
        int size;
        string array;
        bool isError = false;
        bool isFront = true;
        
        cin >> command;
        cin >> size;
        cin >> array;
        
        deque<int> DQ;
        
        
        array.erase(0,1);
        array.erase(array.size()-1,1);
        
        istringstream iss(array);
        string token;
        while (getline(iss, token, ','))  DQ.push_back(stoi(token));
        
        for(int i = 0; i < command.size(); i++)
        {
            if (command[i] == 'R') isFront = !isFront;
            else if (command[i] == 'D')
            {
                if (DQ.empty())
                {
                    cout << "error";
                    isError = true;
                    break;
                }
                else
                {
                    if(isFront)  DQ.pop_front();
                    else  DQ.pop_back();
                }
            }
        }
        if (!isError)
        {
            cout << "[";
            if(isFront)
            {
                for(int i = 0; i < DQ.size(); i++)
                {
                    cout << DQ[i];
                    if (i != DQ.size()-1) cout << ",";
                }
            }
            else
            {
                for(int i = DQ.size()-1; i >= 0; i--)
                {
                    cout << DQ[i];
                    if (i != 0) cout << ",";
                }
            }
            cout << "]";
        }
        
        cout << "\n";
    }
}