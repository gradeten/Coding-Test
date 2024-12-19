#include <iostream>
using namespace std;

int main()
{
    int n, m;
    int a;
    cin >> n >> m;
    int arrA[n][m] = {};
    int arrB[n][m] = {};
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a;
            arrA[i][j] = a;
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a;
            arrB[i][j] = a;
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << arrA[i][j] + arrB[i][j] << " ";
        }
        cout << endl;
    }
    
}