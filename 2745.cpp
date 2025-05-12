#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string N;
    int B;
    cin >> N >> B;

    int result = 0;
    int power = 1;

    for (int i = N.size() - 1; i >= 0; i--) {
        char c = N[i];
        int value;
        if (c >= '0' && c <= '9') {
            value = c - '0';
        } else { // 'A' ~ 'Z'
            value = c - 'A' + 10;
        }
        result += value * power;
        power *= B;
    }

    cout << result << endl;
    return 0;
}