#include <iostream>
#include <string>
#include <vector>
using namespace std;

string fizzbuzz(int x) {
    if (x % 15 == 0) return "FizzBuzz";
    if (x % 3 == 0) return "Fizz";
    if (x % 5 == 0) return "Buzz";
    return to_string(x);
}

int main() {
    vector<string> input(3);
    for (int i = 0; i < 3; ++i) cin >> input[i];

    // 숫자가 있는 위치를 찾아 시작점 추정
    for (int i = 0; i < 3; ++i) {
        if (isdigit(input[i][0])) {
            int val = stoi(input[i]);
            int start = val - i;
            // 추정 시작점부터 체크
            bool ok = true;
            for (int j = 0; j < 3; ++j) {
                if (fizzbuzz(start + j) != input[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << fizzbuzz(start + 3) << "\n";
                return 0;
            }
        }
    }

    // 숫자가 없으면 1부터 brute-force
    for (int i = 1; ; ++i) {
        if (fizzbuzz(i) == input[0] &&
            fizzbuzz(i + 1) == input[1] &&
            fizzbuzz(i + 2) == input[2]) {
            cout << fizzbuzz(i + 3) << "\n";
            break;
            }
    }
}