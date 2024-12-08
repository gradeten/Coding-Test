#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string s;
    int n = 0;
    getline(cin, s);
    
    istringstream stream(s);
    string word;
    
    while (stream >> word)
    {
        n++;
    }
    
    cout << n;
}