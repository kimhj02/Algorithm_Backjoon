//
// Created by 김현진 on 25. 4. 23.
//
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    int s1_int = stoi(s1);
    int s2_int = stoi(s2);
    int total = s1_int + s2_int;

    string s_total = to_string(total);
    reverse(s_total.begin(), s_total.end());

    int result = stoi(s_total);
    cout << result << endl;

    return 0;
}