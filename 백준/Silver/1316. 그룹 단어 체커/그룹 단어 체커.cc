#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string s;
    int groupCount = 0;
    
    cin >> n;

    
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        bool isGroup = true;
        bool appeared[26] = {false};
        appeared[s[0]-'a'] = true;
        
        for(int j = 1; j < s.size(); j++)
        {
            if (s[j] != s[j-1])
            {
                if (appeared[s[j]-'a'])
                {
                    isGroup = false;
                    break;
                }
                appeared[s[j]-'a'] = true;
            }
        }
        
        if(isGroup) groupCount++;
    }
    
    cout << groupCount;
}