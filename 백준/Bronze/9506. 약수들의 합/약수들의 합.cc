#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    int sum = 0;
    vector<int> v;
    cin >> n;
    
    while(n != -1)
    {
        sum = 0;
        v = {};
        
        for(int i = 1; i<= n-1; i++)
        {
            if (n % i == 0)
            {
                v.push_back(i);
            }
        }
        
        int size = v.size();
        
        for(int j = 0; j < size; j++)
        {
            sum += v[j];
        }

        if(sum == n)
        {
            cout << n << " = ";
            for(int j = 0; j < size; j++)
            {
                cout << v[j];
                if (j != size-1) cout << " + ";
            }
            cout << endl;
        }
        else
        {
            cout << n << " is NOT perfect." << endl;
        }
        
        cin >> n;
    }
}