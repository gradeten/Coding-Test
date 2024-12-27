#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int point;
    int n;
    cin >> n;
    
    point = pow(2, n) + 1;
    cout << point * point;
}