//
// Created by 김현진 on 25. 5. 5.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> heights(N);
    for (int i = 0; i < N; ++i) {
        cin >> heights[i];
    }

    int max_diff = 0;
    int start = heights[0];

    for (int i = 1; i < N; ++i) {
        if (heights[i] > heights[i - 1]) {
            // 오르막길 계속
            max_diff = max(max_diff, heights[i] - start);
        } else {
            // 오르막길 종료
            start = heights[i];
        }
    }

    cout << max_diff << endl;
    return 0;
}