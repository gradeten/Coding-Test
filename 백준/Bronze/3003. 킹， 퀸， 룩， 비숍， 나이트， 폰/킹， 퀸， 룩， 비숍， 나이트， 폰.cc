#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(6);
    vector<int> answer = {1,1,2,2,2,8};
    int a;
    
    for(int i = 0; i < 6; i++)
    {
        cin >> a;
        v[i] = a;
    }
    
    for(int i = 0; i < 6; i++)
    {
        v[i] = answer[i] - v[i];
    }
    
    for(int i = 0; i < 6; i++)
    {
        cout << v[i] << " ";
    }
    
}