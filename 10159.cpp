#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int object_num, compare_num;
    cin >> object_num >> compare_num;

    vector<vector<int>> matrix;
    vector<int> result;
    result.assign(object_num+1, 0);
    matrix.assign(object_num+1, vector<int>(object_num+1, 0));

    for (int i = 1; i <= compare_num; i++) {
        int big, small;
        cin >> big >> small;
        matrix[big][small] = 1; //
        matrix[small][big] = 2; //방향을 확인해야함
    }

    for (int k = 1; k <= object_num; k++) {
        for (int i = 1; i <= object_num; i++) {
            for (int j = 1; j <= object_num; j++) {
                if (matrix[i][k] == 1 && matrix[k][j] == 1) { //비교 정보가 존재한다면
                    matrix[i][j] = 1;
                    matrix[j][i] = 2;
                }
                else if (matrix[i][k] == 2 && matrix[k][j] == 2) {
                    matrix[i][j] = 2;
                    matrix[j][i] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= object_num; i++) {
        for (int j = 1; j <= object_num; j++) {
            if (matrix[i][j] == 0) { //정보가 없다면
                result[i]++;
            }
        }
    }

    for (int i = 1; i <= object_num; i++) {
        cout << result[i]-1 << endl;
    }
    return 0;
}
//물건 n개 있음, 물건에 번호 1부터 n까지 있음
//각 물건의 무게 비교 결과가 주어짐
//앞에 있는게 뒤에 있는것보다 큰것
//물건의 개수 n과 일부 물건 쌍의 비교 결과가 주어졌을 때, 각 물건에 대해서
//그 물건과의 비교 결과를 알 수 없는 ㅁ루건의 개수를 출력하는 프로그램 작성

