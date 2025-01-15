#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    ll sum = 0;
    ll xor_val = 0;

    int m;
    cin >> m;
    while (m--) {
        int q;
        cin >> q;

        int x;
        switch (q) {
            case 1:
                cin >> x;
            sum += x;
            xor_val ^= x;
            break;

            case 2:
                cin >> x;
            sum -= x;
            xor_val ^= x;
            break;

            case 3:
                cout << sum << '\n';
            break;

            case 4:
                cout << xor_val << '\n';
            break;
        }
    }

    return 0;
}
