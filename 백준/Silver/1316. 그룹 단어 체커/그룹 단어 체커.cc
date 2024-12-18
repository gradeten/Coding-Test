#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    string s;
    int groupCount = 0;
    vector<char> v;
    
    cin >> n;

    
    for(int i = 0; i < n; i++)
    {
        bool isGroup = true;
        cin >> s;
        v.push_back(s[0]);
        
        for(int j = 1; j < s.size(); j++)
        {
            if (count(v.begin(), v.end(), s[j]) != 0 && s[j-1] != s[j])
            {
                isGroup = false;
                break;
            }
            else
            {
                v.push_back(s[j]);
            }
        }
        
        if(isGroup) groupCount++;
        v.clear();
    }
    
    cout << groupCount;
}