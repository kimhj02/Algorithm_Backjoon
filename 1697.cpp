//
// Created by 김현진 on 25. 6. 1.
//
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N = 0, K = 0;
    cin >> N >> K;

    const int MAX = 100001;
    vector<bool> visited(MAX, false);
    queue<pair<int, int>> q; // pair<현재 위치, 시간>

    q.push({N, 0});
    visited[N] = true;

    while (!q.empty()) {
        int current = q.front().first;
        int time = q.front().second;
        q.pop();

        if (current == K) { //도착하면
            cout << time << endl;
            return 0;
        }

        int next_positions[3] = {current - 1, current + 1, current * 2};
        for (int next : next_positions) {
            if (next >= 0 && next < MAX && !visited[next]) {
                visited[next] = true;
                q.push({next, time + 1});
            }
        }
    }

    return 0;
}