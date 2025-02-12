#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<vector<int>> arr;
vector<int> rank1;
int visited[10001];

int DFS(int start) {
    visited[start] = 1;
    int count = 1;

    for (int next : arr[start]) {
        if (!visited[next]) {
            count += DFS(next);
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int com_num, edge_num;
    cin >> com_num >> edge_num;

    arr.resize(com_num + 1);
    rank1.resize(com_num + 1, 0);

    for (int i = 0; i < edge_num; i++) {
        int start, end;
        cin >> start >> end;
        arr[end].push_back(start);
    }

    int max_hack = 0;
    for (int i = 1; i <= com_num; i++) {
        memset(visited, 0, sizeof(visited));
        rank1[i] = DFS(i);
        max_hack = max(max_hack, rank1[i]);
    }

    for (int i = 1; i <= com_num; i++) {
        if (rank1[i] == max_hack) {
            cout << i << " ";
        }
    }
}