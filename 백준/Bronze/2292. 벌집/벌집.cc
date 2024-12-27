#include <iostream>
using namespace std;

int main()
{
    int n;
    int layer = 1;
    int max_layer = 1;
    cin >> n;
    
    if (n == 1)
    {
        cout << 1;
    }
    else
    {
        while (n > max_layer)
        {
            layer++;
            max_layer += 6*(layer-1);
        }
        cout << layer;
    }
    
}