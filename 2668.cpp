#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
vector<bool> visited;
vector<bool> finished;
vector<int> result;

void dfs(int start, int current) {
    visited[current] = true;
    int next = arr[current];

    if (!visited[next]) {
        dfs(start, next);
    } else if (!finished[next]) {
        // 사이클이 형성된 경우
        if (start == next) {
            result.push_back(start);
        }
    }

    finished[current] = true;
}

int main() {
    int n;
    cin >> n;

    arr.resize(n + 1);
    visited.resize(n + 1, false);
    finished.resize(n + 1, false);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        fill(visited.begin(), visited.end(), false);
        fill(finished.begin(), finished.end(), false);
        dfs(i, i);
    }

    sort(result.begin(), result.end());

    cout << result.size() << '\n';
    for (int num : result) {
        cout << num << '\n';
    }

    return 0;
}