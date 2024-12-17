#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    string alphabets [8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    
    cin >> s;
    
    for(int i = 0; i < 8; i++)
    {
        size_t pos = s.find(alphabets[i]);
        while (pos != string::npos)
        {
            s.replace(pos, alphabets[i].length() ,"a");
            pos = s.find(alphabets[i], pos + 1);
        }
    }
    
    cout << s.length();
    
}