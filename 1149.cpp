#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int case_num = 0;
    cin >> case_num; // 집의 수

    vector<vector<int>> color(case_num, vector<int>(3));
    for (int i = 0; i < case_num; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> color[i][j];
        }
    }

    vector<vector<int>> dp(case_num, vector<int>(3));
    dp[0][0] = color[0][0];
    dp[0][1] = color[0][1];
    dp[0][2] = color[0][2];

    for (int i = 1; i < case_num; i++) {
        dp[i][0] = color[i][0] + min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = color[i][1] + min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = color[i][2] + min(dp[i-1][0], dp[i-1][1]);
    }

    int result = min({dp[case_num-1][0], dp[case_num-1][1], dp[case_num-1][2]});
    cout << result << endl;

    return 0;
}

//RGB 거리에는 집에 n개가 있음
//거리는 선분으로 나타낼 수 있고, 1번 집부터 n번 집이 순서대로 존재
//집은 빨강, 초록, 파랑 중 하나의 색으로 칠해®야 함
//각각의 집을 빨강, 초록, 파알으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구하자

//조건 1 : 1번 집의 색은 2번 집의 색과 같지 않아야 한다
//조건 2 : n번 집의 색은 n-1번 집의 색과 같지 않아야 한다
//조건 3 : i번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다