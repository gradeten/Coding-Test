#include <iostream>
using namespace std;

bool isprime(int n){
    if (n == 1) return 0;
    for(int i = 2; i*i <= n; i++){
        if (n % i == 0) return 0;
    }
    return 1;
}

int main()
{
    int n, a;
    cin >> n;

    int sum = 0;
    
    for(int i = 0; i < n; i++){
        cin >> a;
        sum += isprime(a);
    }
    
    cout << sum;
}