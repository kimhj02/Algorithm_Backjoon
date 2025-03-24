#include <iostream>
using namespace std;

int main() {

    int a = 0, b = 0, n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        a += num;
    }

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        b += num;
    }
    cout << b << ' ' << a;
    return 0;
}