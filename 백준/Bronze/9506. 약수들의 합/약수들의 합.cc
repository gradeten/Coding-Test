#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    vector<int> v;
    cin >> n;
    
    while(n != -1)
    {
        int sum = 0;
        v.clear();
        
        for(int i = 1; i<= n/2; i++)
        {
            if (n % i == 0)
            {
                v.push_back(i);
            }
        }
        
        for(int val: v)
        {
            sum += val;
        }

        if(sum == n)
        {
            cout << n << " = ";
            for(int j = 0; j < v.size(); j++)
            {
                cout << v[j];
                if (j != v.size()-1) cout << " + ";
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