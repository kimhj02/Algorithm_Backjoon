#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9; // 무한대 값 설정

int main() {
    int city_num, road_num;
    cin >> city_num >> road_num;

    // 인접 행렬 초기화 (INF로 초기화)
    vector<vector<int>> matrix(city_num + 1, vector<int>(city_num + 1, INF));

    // 도로 정보 입력
    for (int i = 0; i < road_num; i++) {
        int start, end, value;
        cin >> start >> end >> value;
        matrix[start][end] = value; // 일방 통행
    }

    // 플로이드-워셜 알고리즘
    for (int k = 1; k <= city_num; k++) {
        for (int i = 1; i <= city_num; i++) {
            for (int j = 1; j <= city_num; j++) {
                if (matrix[i][k] != INF && matrix[k][j] != INF) { // INF 체크
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }

    // 최소 사이클 찾기 (i → i 최소값 찾기)
    int min_cycle = INF;
    for (int i = 1; i <= city_num; i++) {
        if (matrix[i][i] != INF) { // 초기 INF 값은 무시
            min_cycle = min(min_cycle, matrix[i][i]);
        }
    }

    // 사이클이 없으면 -1 출력
    if (min_cycle == INF) cout << -1 << endl;
    else cout << min_cycle << endl;

    return 0;
}