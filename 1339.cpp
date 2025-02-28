#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct Alphabet {
    char a;
    int count;
};

bool compare(const Alphabet &a, const Alphabet &b) {
    return a.count > b.count;
}

int main() {
    int test_case;
    cin >> test_case;
    vector<string> v(test_case);
    vector<int> alphabets(26, 0);

    for (int i = 0; i < test_case; i++) {
        cin >> v[i];
        int length = v[i].length();
        for (int j = 0; j < length; j++) {
            alphabets[v[i][j] - 'A'] += pow(10, length - j - 1);
        }
    }

    vector<pair<int, char>> alpha_weight;
    for (int i = 0; i < 26; i++) {
        if (alphabets[i] > 0) {
            alpha_weight.push_back({alphabets[i], char(i + 'A')});
        }
    }

    sort(alpha_weight.begin(), alpha_weight.end(), greater<>());

    int num = 9, result = 0;
    for (const auto &p : alpha_weight) {
        result += p.first * num;
        num--;
    }

    cout << result << endl;
    return 0;
}