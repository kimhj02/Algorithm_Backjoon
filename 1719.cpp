#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 2147483647

int main() {
    int vertex_num, edge_num;
    cin >> vertex_num >> edge_num;
    vector<vector<int>> matrix;
    vector<vector<int>> result;
    matrix.assign(vertex_num + 1, vector<int>(vertex_num + 1, INF)); //초기 무제한 설정
    result.assign(vertex_num + 1, vector<int>(vertex_num + 1, -1)); //경로표 초기화 (-1)

    for (int i = 1; i < vertex_num + 1; i++) { //자기 자신까지의 거리 0
        matrix[i][i] = 0;
    }

    for (int i = 0; i < edge_num; i++) { //횟수를 확인하는 거라 1-index 사용할 필요 없음
        int start, end, value;
        cin >> start >> end >> value; //입력
        matrix[start][end] = value; //양방향 연결
        matrix[end][start] = value; //양방향 연결
        //result vector 초기화
        result[start][end] = end; //도착점으로
        result[end][start] = start; //도착점으로
    }

    for (int k = 1; k < vertex_num + 1; k++) {
        for (int i = 1; i < vertex_num + 1; i++) {
            for (int j = 1; j < vertex_num + 1; j++) {
                if (matrix[i][k] != INF && matrix[k][j] != INF) { //k를 거치는 경로가 존재한다면
                    if (matrix[i][j] > matrix[i][k] + matrix[k][j]) { //최단거리 갱신 가능
                        matrix[i][j] = matrix[i][k] + matrix[k][j]; // 최단 거리 갱신
                        result[i][j] = result[i][k]; // i에서 j까지 가는 첫 번째 정점 저장
                    }
                }
            }
        }
    }

    for (int i = 1; i < vertex_num + 1; i++) {
        for (int j = 1; j < vertex_num + 1; j++) {
            if (i == j)
                cout << "- ";
            else
                cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}