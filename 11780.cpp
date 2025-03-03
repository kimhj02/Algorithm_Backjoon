#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 2147483647

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int city_num = 0, bus_num = 0;
    cin >> city_num >> bus_num;

    // cost(최소 비용)을 저장할 2차원 벡터와 경로 복원을 위한 next 배열을 선언
    vector<vector<int>> matrix(city_num, vector<int>(city_num, INF));
    vector<vector<int>> next(city_num, vector<int>(city_num, -1));

    // 자기 자신은 0으로 초기화
    for (int i = 0; i < city_num; i++) {
        matrix[i][i] = 0;
    }

    // 간선(버스 노선) 입력: 시작, 끝, 가중치
    for (int i = 0; i < bus_num; i++) {
        int start = 0, end = 0, value = 0;
        cin >> start >> end >> value;
        // 입력은 1-indexed이므로 0-indexed로 변환
        start--; end--;
        // 여러 노선이 있을 경우, 더 작은 값을 선택
        if(value < matrix[start][end]) {
            matrix[start][end] = value;
            next[start][end] = end; // 바로 도착하는 경로로 초기화
        }
    }

    // 플로이드-워셜 알고리즘
    // k: 중간 경유 정점, i: 시작 정점, j: 도착 정점
    for (int k = 0; k < city_num; k++) {
        for (int i = 0; i < city_num; i++) {
            for (int j = 0; j < city_num; j++) {
                // i->k 또는 k->j로 가는 경로가 없으면 continue
                if (matrix[i][k] == INF || matrix[k][j] == INF) continue;
                // 더 짧은 경로가 있으면 갱신
                if (matrix[i][j] > matrix[i][k] + matrix[k][j]) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                    next[i][j] = next[i][k];  // 경로 복원을 위해 next 배열 갱신
                }
            }
        }
    }

    // 각 위치에서의 최소 비용 출력
    for (int i = 0; i < city_num; i++) {
        for (int j = 0; j < city_num; j++) {
            // 경로가 없으면 0 출력
            if(matrix[i][j] == INF)
                cout << 0 << " ";
            else
                cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // 각 위치에서의 경로 출력
    // i에서 j로 가는 경로가 없거나 자기 자신인 경우 0 출력
    for (int i = 0; i < city_num; i++) {
        for (int j = 0; j < city_num; j++) {
            if(i == j || next[i][j] == -1) {
                cout << 0 << "\n";
            } else {
                // 경로 복원: i에서 j까지의 경로를 next 배열을 통해 복원
                vector<int> path;
                int cur = i;
                path.push_back(cur);
                while(cur != j) {
                    cur = next[cur][j];
                    path.push_back(cur);
                }
                // 경로에 포함된 정점의 개수와 정점 번호 출력 (출력 시 1-indexed로 변환)
                cout << path.size() << " ";
                for (int node : path) {
                    cout << node + 1 << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}