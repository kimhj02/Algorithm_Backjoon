//
// Created by 김현진 on 25. 5. 25.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> count(26, 0); // 알파벳 A~Z 카운트

    // 대소문자 처리 및 카운트
    for (char c : s) {
        if (c >= 'a' && c <= 'z') c = c - 'a' + 'A';
        count[c - 'A']++;
    }

    int maxCount = 0;
    int maxIndex = -1;
    bool isDuplicate = false;

    // 최대값 찾기 및 중복 여부 확인
    for (int i = 0; i < 26; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            maxIndex = i;
            isDuplicate = false;
        } else if (count[i] == maxCount && maxCount != 0) {
            isDuplicate = true;
        }
    }

    if (isDuplicate) {
        cout << "?" << endl;
    } else {
        cout << char('A' + maxIndex) << endl;
    }

    return 0;
}