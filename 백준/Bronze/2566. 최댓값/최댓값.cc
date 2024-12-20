#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> v(9, vector<int>(9));
    int max = 0;
    int row, col;
    
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cin >> v[i][j];
            if (v[i][j] > max)
            {
                max = v[i][j];
                row = i;
                col = j;
            }
        }
    }
    
    cout << max << endl;
    cout << row+1 << " " << col+1;
    
    
}