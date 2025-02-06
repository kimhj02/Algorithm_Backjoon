#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;


ll find_level(ll exp) {
    ll left = 0, right = 1e9, answer = 0;

    while (left <= right) {
        ll mid = (left + right) / 2;
        if (mid * (mid + 1) <= exp) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return answer + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int test_case;
    cin >> test_case;

    for (int i = 0; i < test_case; i++) {
        ll N;
        cin >> N;
        ll total_exp = N * (N + 1) / 2;
        cout << find_level(total_exp) << "\n";
    }

    return 0;
}