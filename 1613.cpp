#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    static int dist[401][401];
    // 초기에는 모두 0 (모름)

    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;  // a가 b보다 먼저
    }

    // 플로이드–와샬
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            if (dist[i][k] == 0) continue;
            for (int j = 1; j <= N; j++) {
                if (dist[k][j] == 1)
                    dist[i][j] = 1;
            }
        }
    }

    int S;
    cin >> S;
    while (S--) {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == 1) {
            cout << -1 << "\n";
        } else if (dist[b][a] == 1) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }

    return 0;
}