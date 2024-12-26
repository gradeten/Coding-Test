#include <iostream>
using namespace std;

int main()
{
    int n, t;
    int array[4] = {25,10,5,1};
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        
        for(int j = 0; j < 4; j++)
        {
            cout <<  t / array[j] << " ";
            t = t % array[j];
        }
        cout << endl;
    }
}