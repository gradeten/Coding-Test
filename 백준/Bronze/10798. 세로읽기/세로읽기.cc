#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<char>> v;
    string line;
    
    for(int i = 0; i < 5; i++)
    {
       getline(cin, line);
       vector<char> row(line.begin(), line.end());
       v.push_back(row);
    }
    
    
    for(int j = 0; j < 15; j++)
    {
        for(int i = 0; i < 5; i++)
        {
            if (j < v[i].size())
            {
                cout << v[i][j];
            }
        }
    }
}