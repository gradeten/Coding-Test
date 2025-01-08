#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, a;
    vector<int> x;
    vector<int> y;
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        x.push_back(a);
        cin >> a;
        y.push_back(a);
    }
    
    int width = (*max_element(x.begin(), x.end())) - (*min_element(x.begin(), x.end()));
    int height = (*max_element(y.begin(), y.end())) - (*min_element(y.begin(), y.end()));
    cout << width * height;
}