//
// Created by 김현진 on 25. 6. 5.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    string merged;

    for (int i = 0; i < s1.length(); i++) {
        merged += s1[i];
        merged += s2[i];
    }

    vector<int> result;
    for (char c : merged) {
        result.push_back(c - '0');
    }

    while (result.size() > 2) {
        vector<int> temp;
        for (int i = 0; i < result.size() - 1; i++) {
            int sum = (result[i] + result[i + 1]) % 10;
            temp.push_back(sum);
        }
        result = temp;
    }

    cout << result[0] << result[1] << endl;

    return 0;
}