#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    string s;
    int freq[26] = {0};
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
        freq[s[i] - 'A']++;
    }
    
    for(int i = 0; i < 26; i++)
    {
        if (freq[i] > max)
        {
            max = freq[i];
            alphabet = 'A' + i;
            is_duplicate = false;
        }
        else if (freq[i] == max)
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