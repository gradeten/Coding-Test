#include <iostream>
using namespace std;

void printStar(int i, int n)
{
    for(int j = 1; j <= (2*n - 1 - i)/2; j++)
        {
            cout << " ";
        }
        for(int j = 0; j < i; j++) cout << "*";
        cout << endl;
}


int main()
{
    int n;
    cin >> n;
    
    for(int i = 1; i <= 2*n-1; i+=2)
        {
            printStar(i, n);
        }
    
        for(int i = 2*n-3; i >= 1; i-=2)
        {
            printStar(i, n);
        }
    
}


