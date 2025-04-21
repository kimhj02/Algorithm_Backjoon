//
// Created by 김현진 on 25. 4. 21.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int a1, a2, b1, b2;
    cin >> a1 >> a2;
    cin >> b1 >> b2;
    int differ1 = abs(a1 + b2);
    int differ2 = abs(a2 + b1);
    if (differ1 < differ2) {
        cout << differ1;
    } else {
        cout << differ2;
    }
    return 0;
}