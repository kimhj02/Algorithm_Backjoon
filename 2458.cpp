#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> matrix;

int main() {
    int student_num = 0, compare_num = 0;
    cin >> student_num >> compare_num;
    matrix.assign(student_num, vector<int>(student_num, 0));

    for (int i = 0; i < compare_num; i++) {
        int small = 0, big = 0;
        cin >> small >> big;
        small--;
        big--;
        matrix[small][big] = 1;
    }

    for (int k = 0; k < student_num; k++) {
        for (int i = 0; i < student_num; i++) {
            for (int j = 0; j < student_num; j++) {
                if (matrix[i][k] && matrix[k][j]) {
                    matrix[i][j] = 1;
                }
            }
        }
    }

    int result = 0;
    for (int i = 0; i < student_num; i++) {
        int count = 0;
        for (int j = 0; j < student_num; j++) {
            if (i == j) continue;
            if (matrix[i][j] == 1 || matrix[j][i] == 1) { //정보를 알고 있으면 증가
                count++;
            }
        }
        if (count == student_num - 1) //전체 -1이면 알고 있음
            result++;
    }

    cout << result << endl;
    return 0;
}