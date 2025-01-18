#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Shortcut {
    int start;
    int end;
    int length;
};

int main() {
    int N, D;
    cin >> N >> D;

    vector<Shortcut> shortcuts;
    for (int i = 0; i < N; ++i) {
        int start, end, length;
        cin >> start >> end >> length;
        if (end <= D && end - start > length) {
            shortcuts.push_back({start, end, length});
        }
    }

    vector<int> distance(D + 1, 1e9);
    distance[0] = 0;

    for (int i = 0; i <= D; ++i) {
        if (i < D) {
            distance[i + 1] = min(distance[i + 1], distance[i] + 1);
        }

        for (const auto &shortcut : shortcuts) {
            if (shortcut.start == i) {
                distance[shortcut.end] = min(distance[shortcut.end], distance[i] + shortcut.length);
            }
        }
    }

    cout << distance[D] << endl;

    return 0;
}
