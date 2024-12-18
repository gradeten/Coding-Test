#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    float credit;
    string grade;
    float total_credit = 0;
    float total_grade = 0;
    string grades[8] = {"A+", "A0", "B+", "B0", "C+", "C0", "D+", "D0"};
    
    for(int i = 0; i < 20; i++)
    {
                cin >> s >> credit >> grade;
                if (grade == "P")
                {
                    continue;
                }
                else if (grade == "F")
                {
                    total_credit+=credit;
                }
                else
                {
                    total_credit+=credit;
                    int index = find(grades, grades + 8, grade) - grades;
                    total_grade += (4.5-0.5*index)*(credit);
                }
    }
    
    cout << (total_grade/total_credit);
}