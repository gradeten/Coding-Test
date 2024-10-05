#include <iostream>
using namespace std;

int main(){
    int h, m;
    cin >> h >> m;
    if ( m >= 45){
        m = m - 45;
    }
    else{
        m = 60 - (45 - m);
        if (h==0){
            h = 23;
        }
        else{
            h = h - 1;  
        }
    }
    cout << h << " " << m;
}