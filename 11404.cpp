#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 2147483647; // 무한대를 의미하는 값

vector<vector<int>> matrix;

int main() {
    int city_num = 0, vertex_num = 0;
    cin >> city_num >> vertex_num;

    // 1-indexed로 사용할 것이므로 city_num+1 크기로 할당
    matrix.assign(city_num+1, vector<int>(city_num+1, INF));

    // 자기 자신으로의 경로는 0으로 초기화
    for (int i = 1; i <= city_num; i++) {
        matrix[i][i] = 0;
    }

    // 간선 입력
    for (int i = 0; i < vertex_num; i++) {
        int start = 0, end = 0, value = 0;
        cin >> start >> end >> value; // 시작 정점, 끝 정점, 가중치
        matrix[start][end] = value;
    }

    // 플로이드-워셜 알고리즘 (1-indexed)
    for (int k = 1; k <= city_num; k++) {
        for (int i = 1; i <= city_num; i++) {
            for (int j = 1; j <= city_num; j++) {
                if (matrix[i][k] != INF && matrix[k][j] != INF) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }

    // 결과 출력
    for (int i = 1; i <= city_num; i++) {
        for (int j = 1; j <= city_num; j++) {
            if(matrix[i][j] == INF)
                cout << "INF" << " ";
            else
                cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}