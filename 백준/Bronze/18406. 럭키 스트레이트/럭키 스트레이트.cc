#include <iostream>
#include <string>
using namespace std;

int sum_digit(const string& str, int start, int end) {
    int sum = 0;
    for (int i = start; i < end; i++) {
        sum += str[i] - '0';  
    }
    return sum;
}

int main() {
    string input;
    cin >> input;

    int length = input.length();  
    int half = length / 2;  

    int left_sum = sum_digit(input, 0, half);
    int right_sum = sum_digit(input, half, length);

    if (left_sum == right_sum) {
        cout << "LUCKY" << endl;
    } else {
        cout << "READY" << endl;
    }

    return 0;
}