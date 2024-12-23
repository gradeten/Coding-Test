#include <iostream>
using namespace std;

int main()
{
    string n;
    int b;
    int res = 0;
    cin >> n >> b;
    int exp = 1;

    for (int i = n.length()-1; i >= 0; i--)
    {
        if (n[i] >= '0' && n[i] <= '9') 
        {
            res = res + exp * (n[i] - '0');
            exp = exp * b;
        }
        else 
        {
            res = res + exp * (n[i] - 'A' + 10);
            exp = exp * b;
        }
    }
    
    cout << res;
}
    
