//
// Created by 김현진 on 25. 5. 2.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

    long long n, k;
    cin >> n >> k;
    long long result = 0;
    for (int i = 1; i <= n; ++i) {
        long long temp = i;
        long long digits = 1;
        while (temp >= 10) {
            temp /= 10;
            digits *= 10;
        }
        result = (result * digits * 10 + i) % k;
    }
    cout << result;
    return 0;
}