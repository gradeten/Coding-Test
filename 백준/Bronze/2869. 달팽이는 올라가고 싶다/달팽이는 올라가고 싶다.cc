#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, v;
    cin >> a >> b >> v;
    int answer;
    answer = ceil((v-a)/(a-b)) + 1;
    
    cout << answer;

}