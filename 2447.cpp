//
// Created by 김현진 on 25. 6. 2.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void star(vector<vector<char>>& map, int x, int y, int size) {
    if (size == 1) {
        map[x][y] = '*';
        return;
    }

    int next = size / 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == 1 && j == 1)
                continue;
            star(map, x + i * next, y + j * next, next);
        }
    }
}

int main() {
    int N;
    cin >> N;

    vector<vector<char>> map(N, vector<char>(N, ' '));
    star(map, 0, 0, N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << map[i][j];
        }
        cout << endl;
    }

    return 0;
}