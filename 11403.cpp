#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int vertex_num = 0;
    cin >> vertex_num;

    // 인접 행렬 초기화 (입력값은 0 또는 1)
    vector<vector<int>> matrix(vertex_num, vector<int>(vertex_num, 0));

    for (int i = 0; i < vertex_num; i++) {
        for (int j = 0; j < vertex_num; j++) {
            cin >> matrix[i][j]; // i에서 j로의 연결 여부 (방향 그래프)
        }
    }

    // 플로이드-워셜 알고리즘 적용
    // k: 중간 경유 정점, i: 시작 정점, j: 도착 정점
    for (int k = 0; k < vertex_num; k++) {
        for (int i = 0; i < vertex_num; i++) {
            for (int j = 0; j < vertex_num; j++) {
                // i에서 k를 거쳐 j로 갈 수 있으면 경로가 있다고 설정
                if (matrix[i][k] && matrix[k][j]) {
                    matrix[i][j] = 1;
                }
            }
        }
    }

    // 결과 출력
    for (int i = 0; i < vertex_num; i++) {
        for (int j = 0; j < vertex_num; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}