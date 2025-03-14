#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define INT_MAX 2147483647

struct node {
    int x,y;
    int special;
};

int main() {
    int city_num = 0, tele_time = 0;
    cin >> city_num >> tele_time;
    vector<node> arr; //도시의 정보 저장용 벡터
    arr.resize(city_num+1); //도시가 6개라면 인덱스는 0에서 6까지 총 7개, 하지만 0은 쓰지 않음
    for (int i = 1; i <= city_num; i++) {
        int special, x, y;
        cin >> special >> x >> y;
        arr[i].x = x;
        arr[i].y = y;
        arr[i].special = special;
    }
    vector<vector<int>> matrix;
    matrix.assign(city_num+1, vector<int>(city_num+1, INT_MAX));

    for (int i = 1; i <= city_num; i++) {
        matrix[i][i] = 0; //자기 자신까지의 거리는 0
    }

    for (int i = 1; i <= city_num; i++) {
        for (int j = 1; j <= city_num; j++) {
            if (arr[i].special == 1 && arr[j].special == 1) {
                //둘 다 특별한 도시라면
                matrix[i][j] = tele_time; //
                matrix[j][i] = tele_time;
            }
            //하나만 특별 or 둘 다 특별 x
            matrix[i][j] = min(abs(arr[i].x - arr[j].x) + abs(arr[i].y - arr[j].y),matrix[i][j]);
            matrix[j][i] = min(abs(arr[j].x - arr[i].x) + abs(arr[j].y - arr[i].y),matrix[j][i]);
        }
    }
    for (int k = 1; k <= city_num; k++) {
        for (int i = 1; i <= city_num; i++) {
            for (int j = 1; j <= city_num; j++) {
                if (matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX) { //연결되어 있으면
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]); //최단거리 계산
                }
            }
        }
    }
    //각 케이스마다 출력
    int test_case = 0;
    cin >> test_case;
    for (int i = 0; i < test_case; i++) {
        int start, end;
        cin >> start >> end;
        cout << matrix[start][end] << endl;
    }
    return 0;
}

//2차원 평면 위에 n개의 도시 존재
//일부 도시는 특별한 도시
//r1,c1에 있는 도시에서 r2,c2에 있는 도시로 가는 이동 시간은
//|r1 - r2| + |c1 - c2|임
//두 도시가 특별한 도시라면, 텔레포트를 이용해서 이동 가능, 텔레포트에 걸리는 시간은 T
//두 도시의 쌍 M개가 주어졌을 때, 최소 이동 시간을 구해보자

//입력 : 도시의 수 N, 텔레포트하는데 걸리는 시간 T
//도시의 정볼 입력 세 정수 s, x, y가 1번 도시붜 N번 도시까지 순서대로 주어짐
//s가 1인 경우는 특별한 도시, 0이면 특별한 도시가 아님, x,y는 좌표