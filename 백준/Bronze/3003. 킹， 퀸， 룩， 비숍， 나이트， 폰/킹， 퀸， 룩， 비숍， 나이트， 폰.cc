#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(6);
    vector<int> answer = {1,1,2,2,2,8};
    
    for(int i = 0; i < 6; i++)
    {
        cin >> v[i];
    }
    
    for(int i = 0; i < 6; i++)
    {
        cout << answer[i] - v[i] << " ";
    }
    
}