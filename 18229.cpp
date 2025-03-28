#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N =0, M = 0, K = 0; //사람 수 N, 손 뻗는 회숫 M, 점원과의 거리 K
    cin >> N >> M >> K;
    vector<vector<int>> matrix(N, vector<int>(M, 0)); //일단 0으로 초기화
    vector<long long> person_length(N,0); //개인마다 거리 입력하는

    for (int i = 0; i < N; i++) { //0-index로 사용하자 (i가 사람 j가 횟수)
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }

    int winner_person = 0, winner_count =0;
    int count = 0;

    bool end = false;
    for (int i = 0; i < M; i++) { //손 뻗는 횟수
        for (int j = 0; j < N; j++) { //사람
            person_length[j] += matrix[j][i]; //앞에게 사람 뒤에게 횟수
            if (person_length[j] >= K) { //이상
                winner_person = j; //사람
                winner_count = i; //횟수
                end = true;
                break;
            }
        }
        if (end) break;
    }
    cout << winner_person+1 << " " << winner_count+1 << endl;
    return 0;
}

//N명이 서로 결제하겠다고 카드를 내밈
//사람들과 점원들 사이의 거리 K
//처음으로 손을 K이상 뻗은 사람이 결제함

//손을 뻗는 과정
