#include <iostream>
#include <cmath> // ceil 사용
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int time;
    cin >> time;

    if (time <= 30) {
        cout << A;
    } else {
        int extra_time = time - 30;
        int additional_fee = ceil((double)extra_time / B) * C;
        cout << A + additional_fee;
    }

    return 0;
}