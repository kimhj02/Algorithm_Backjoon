#include <iostream>
using namespace std;

int main() {
    int test_case;
    cin >> test_case;

    for (int t = 1; t <= test_case; t++) {
        int P, Q;
        cin >> P >> Q;

        long long f1 = 1, f2 = 1, next = 0;

        if (P == 1) {
            cout << "Case #" << t << ": " << f1 % Q << "\n";
            continue;
        }

        if (P == 2) {
            cout << "Case #" << t << ": " << f2 % Q << "\n";
            continue;
        }

        for (int i = 3; i <= P; i++) {
            next = (f1 + f2) % Q;
            f1 = f2;
            f2 = next;
        }

        cout << "Case #" << t << ": " << next << "\n";
    }

    return 0;
}