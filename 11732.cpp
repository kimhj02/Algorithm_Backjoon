#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test_case;
    cin >> test_case;

    int bitmask = 0;
    for (int i = 0; i < test_case; i++) {
        string s;
        int x;
        cin >> s;

        if (s == "add") {
            cin >> x;
            bitmask |= (1 << (x - 1));
        } else if (s == "remove") {
            cin >> x;
            bitmask &= ~(1 << (x - 1));
        } else if (s == "check") {
            cin >> x;
            cout << ((bitmask & (1 << (x - 1))) != 0) << "\n";
        } else if (s == "toggle") {
            cin >> x;
            bitmask ^= (1 << (x - 1));
        } else if (s == "all") {
            bitmask = (1 << 20) - 1;
        } else if (s == "empty") {
            bitmask = 0;
        }
    }

    return 0;
}
