#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int a_total = 0;
    int b_total = 0;
    for (int i = 0; i < 4; i++) {
        int a;
        cin >> a;
        a_total += a;
    }
    for (int i = 0; i < 4; i++) {
        int b;
        cin >> b;
        b_total += b;
    }
    if (a_total > b_total) {
        cout << a_total << endl;
    } else {
        cout << b_total << endl;
    }
    return 0;
}