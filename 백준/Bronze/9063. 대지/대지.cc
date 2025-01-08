#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, x, y;
    int minX = 1000001, maxX = -1000001;
	int minY = 1000001, maxY = -1000001;
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        if (x > maxX) maxX = x;
        if (x < minX) minX = x;
        if (y > maxY) maxY = y;
        if (y < minY) minY = y;
    }
    
    cout << (maxX - minX) * (maxY - minY);
}