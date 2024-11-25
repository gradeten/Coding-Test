#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    for (int i = 97; i <= 122; i++) {
        size_t position = s.find(char(i)); 
        
        if (position != string::npos) {
            cout << position << " ";  
        } 
        else {
            cout << -1 << " ";  
        }
    }
    
}