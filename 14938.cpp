#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 2147483647
int main() {
    int city_num = 0, search_num = 0, road_num = 0;
    cin >> city_num >> search_num >> road_num;

    vector<int> city_list(city_num + 1); // 각 지역에 있는 아이템 개수 저장
    vector<vector<int>> matrix(city_num + 1, vector<int>(city_num + 1, INF)); // 거리 초기화

    // 자기 자신까지의 거리 0으로 초기화
    for (int i = 1; i <= city_num; i++) {
        matrix[i][i] = 0;
    }

    // 각 도시의 아이템 개수 입력
    for (int i = 1; i <= city_num; i++) {
        cin >> city_list[i];
    }

    // 도로 정보 입력
    for (int i = 0; i < road_num; i++) {
        int start, end, value;
        cin >> start >> end >> value;
        matrix[start][end] = value; // 양방향 연결
        matrix[end][start] = value;
    }

    // 플로이드-워셜 알고리즘
    for (int k = 1; k <= city_num; k++) {
        for (int i = 1; i <= city_num; i++) {
            for (int j = 1; j <= city_num; j++) {
                if (matrix[i][k] != INF && matrix[k][j] != INF) { // k를 거치는 경로가 존재하는 경우
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }

    int max_value = 0; // 최대 아이템 개수 저장
    for (int i = 1; i <= city_num; i++) { // 각 도시를 시작점으로 탐색
        int value = city_list[i]; // 자기 자신 포함하여 아이템 개수 초기화
        for (int j = 1; j <= city_num; j++) {
            if (i != j && matrix[i][j] <= search_num) { // 수색 범위 내에 있으면 추가
                value += city_list[j];
            }
        }
        max_value = max(max_value, value);
    }

    cout << max_value << endl;
    return 0;
}