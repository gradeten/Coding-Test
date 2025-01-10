#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    while (a != 0)
    {
        int max = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);

        if (max == a && a >= b + c || max == b && b >= a + c || max == c && c >= a + b)
        {
            cout << "Invalid" << endl;
        }
        else if (a == b && b == c)
        {
            cout << "Equilateral" << endl;
        }
        else if (a == b || b == c || c == a)
        {
            cout << "Isosceles" << endl;
        }
        else
        {
            cout << "Scalene" << endl;
        }
        cin >> a >> b >> c;
    }
}