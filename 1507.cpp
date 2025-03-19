#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int city_num = 0;
    int total = 0;
    cin >> city_num;

    vector<vector<int>> matrix;
    matrix.assign(city_num + 1, vector<int>(city_num + 1, 0));

    for (int i = 1; i < city_num + 1; i++) {
        for (int j = 1; j < city_num + 1; j++) {
            cin >> matrix[i][j]; // 이게 경로를 거쳐서 가는 최소값임, 즉 플로이드-워셜을 진행한 값
        }
    }

    // 이제 이걸 원래 경로로 돌려야 함
    // 표가 대칭임, 자기 자신까지의 경로는 0이고
    vector<vector<bool>> arr(city_num + 1, vector<bool>(city_num + 1, false));

    //확인용
    for (int k = 1; k <= city_num; k++) {
        for (int i = 1; i <= city_num; i++) {
            for (int j = 1; j <= city_num; j++) {
                if (i != j && matrix[i][j] > matrix[i][k] + matrix[k][j]) {
                    cout << "-1" << endl; //최단 거리가 아니므로 -1
                    return 0;
                }
            }
        }
    }

    for (int k = 1; k < city_num + 1; k++) {
        for (int i = 1; i < city_num + 1; i++) {
            for (int j = 1; j < city_num + 1; j++) {
                if (i != j && i != k && j != k) { // 자기 자신을 경유하는 것은 무시
                    if (matrix[i][j] == matrix[i][k] + matrix[k][j]) {
                        arr[i][j] = true; // i->j는 k를 거쳐서 도달 가능 → 직접 연결 X
                    }
                }
            }
        }
    }

    for (int i = 1; i < city_num + 1; i++) {
        for (int j = i + 1; j < city_num + 1; j++) {
            if (!arr[i][j]) {
                total += matrix[i][j];
            }
        }
    }

    cout << total << endl;
}