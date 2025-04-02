// ???
#include <bits/stdc++.h>
using namespace std;

// 문자열로 표현된 두 큰 수를 비교하는 함수
bool isSmaller(string str1, string str2) {
    int n1 = str1.length(), n2 = str2.length();
    
    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;
    
    for (int i = 0; i < n1; i++) {
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;
    }
    
    return false;
}

// 문자열로 표현된 두 큰 수의 뺄셈 함수
string subtract(string str1, string str2) {
    if (isSmaller(str1, str2))
        swap(str1, str2);
    
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    int diff = n1 - n2;
    
    int carry = 0;
    
    for (int i = n2 - 1; i >= 0; i--) {
        int sub = ((str1[i + diff] - '0') - (str2[i] - '0') - carry);
        
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        } else
            carry = 0;
        
        str.push_back(sub + '0');
    }
    
    for (int i = diff - 1; i >= 0; i--) {
        if (str1[i] == '0' && carry) {
            str.push_back('9');
            continue;
        }
        
        int sub = ((str1[i] - '0') - carry);
        
        if (i > 0 || sub > 0)
            str.push_back(sub + '0');
        
        carry = 0;
    }
    
    reverse(str.begin(), str.end());
    
    // 앞의 0 제거
    str.erase(0, min(str.find_first_not_of('0'), str.size() - 1));
    
    return str;
}

// 문자열로 표현된 큰 수의 나눗셈 함수
pair<string, string> divide(string dividend, string divisor) {
    // 나누는 수가 0인 경우
    if (divisor == "0") {
        throw runtime_error("Cannot divide by zero");
    }
    
    // 나누어지는 수가 0인 경우
    if (dividend == "0") {
        return {"0", "0"};
    }
    
    // 나누어지는 수가 나누는 수보다 작은 경우
    if (isSmaller(dividend, divisor)) {
        return {"0", dividend};
    }
    
    // 나누는 수가 1인 경우
    if (divisor == "1") {
        return {dividend, "0"};
    }
    
    // 두 수가 같은 경우
    if (dividend == divisor) {
        return {"1", "0"};
    }
    
    string quotient = "";
    string remainder = "";
    int dividendLength = dividend.length();
    
    // 현재 처리 중인 부분 dividend
    string temp = "";
    temp += dividend[0];
    
    // 나눗셈 과정
    for (int i = 1; i <= dividendLength; i++) {
        // 현재의 temp가 divisor보다 작으면 몫에 0 추가
        while (temp.length() > 0 && temp[0] == '0')
            temp.erase(0, 1);
            
        if (temp.empty() || isSmaller(temp, divisor)) {
            quotient += "0";
            
            if (i < dividendLength)
                temp += dividend[i];
                
            continue;
        }
        
        // temp를 divisor로 최대한 빼보면서 몫을 계산
        int count = 0;
        string originalTemp = temp;
        
        while (!isSmaller(temp, divisor)) {
            temp = subtract(temp, divisor);
            count++;
        }
        
        quotient += to_string(count);
        
        // 다음 자리 처리
        if (i < dividendLength)
            temp += dividend[i];
    }
    
    // 앞의 0 제거
    quotient.erase(0, min(quotient.find_first_not_of('0'), quotient.size() - 1));
    
    // 나머지 반환
    remainder = temp;
    
    if (quotient.empty())
        quotient = "0";
        
    if (remainder.empty())
        remainder = "0";
        
    return {quotient, remainder};
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string n, m;
    cin >> n >> m;
    
    try {
        pair<string, string> result = divide(n, m);
        cout << result.first << '\n';
        cout << result.second;
    } catch (const runtime_error& e) {
        cout << e.what() << '\n';
    }
    
    return 0;
}