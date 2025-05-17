//
// Created by 김현진 on 25. 5. 17.
//
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    while (T.length() > S.length()) {
        if (T.back() == 'A') {
            T.pop_back(); // 'A' 제거
        } else if (T.back() == 'B') {
            T.pop_back(); // 'B' 제거
            reverse(T.begin(), T.end()); // 문자열 뒤집기
        }
    }

    if (T == S) {
        cout << 1 << endl; // 변환 가능
    } else {
        cout << 0 << endl; // 변환 불가능
    }

    return 0;
}