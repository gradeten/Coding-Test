#include <iostream>
#include <algorithm>  
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a == b && b == c) {
        cout << 10000 + a * 1000;
    }
    else if (a == b || b == c || a == c) {
        int same = (a == b) ? a : ((b == c) ? b : c);
        cout << 1000 + same * 100;
    }
    else {
        cout << max({a, b, c}) * 100;
    }
}