#include <iostream>
using namespace std;

int main(){
    int hour;
    int min;
    int time;
    cin >> hour >> min >> time;
    
    hour += (time / 60);
    min += (time % 60);
    
    if (min >= 60)
    {
        hour += 1;
        min -= 60;
    }
    
        
    while (hour >= 24)
    {
        hour -= 24;
    }
    
    cout << hour << " " << min;
    
}