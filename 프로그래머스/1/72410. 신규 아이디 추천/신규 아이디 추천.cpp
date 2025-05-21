#include <string>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    // 1단계: 대문자 → 소문자
    for (char &c : new_id) {
        if (isupper(c)) c = tolower(c);
    }

    // 2단계: 허용 문자만 남기기
    string temp;
    for (char c : new_id) {
        if (islower(c) || isdigit(c) || c == '-' || c == '_' || c == '.') {
            temp += c;
        }
    }

    // 3단계: 마침표(.) 연속 제거
    string result;
    for (char c : temp) {
        if (c == '.' && !result.empty() && result.back() == '.') continue;
        result += c;
    }

    // 4단계: 처음과 끝 마침표 제거
    if (!result.empty() && result.front() == '.') result.erase(result.begin());
    if (!result.empty() && result.back() == '.') result.pop_back();

    // 5단계: 빈 문자열이면 'a'
    if (result.empty()) result = "a";

    // 6단계: 길이 15자 제한, 끝이 '.'면 제거
    if (result.length() > 15) {
        result = result.substr(0, 15);
        if (result.back() == '.') result.pop_back();
    }

    // 7단계: 길이 2 이하면 마지막 문자 반복
    while (result.length() < 3) {
        result += result.back();
    }

    return result;
}
