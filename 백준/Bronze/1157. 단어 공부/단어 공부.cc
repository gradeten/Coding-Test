#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    string s;
    map<char,int> m;
    int max = 0;
    char alphabet;
    bool is_duplicate = false;
    
    cin >> s;
    
    for(int i = 0; i < s.length(); i++)
    {
        s[i] = toupper(s[i]);
    }
    
    for(int i = 0; i < s.length(); i++)
    {
        if(m.count(s[i]) == 0)
        {
            m[s[i]] = 1;
        }
        else
        {
            m[s[i]] += 1;
        }
    }
    
    for(auto j = m.begin(); j != m.end(); j++)
    {
        if (j->second > max)
        {
            max = j->second;
            alphabet = j->first;
            is_duplicate = false;
        }
        else if (j->second == max)
        {
            is_duplicate = true;
        }
    }
    
    if (is_duplicate)
    {
        cout << "?";
    }
    else
    {
        cout << alphabet;
    }
}