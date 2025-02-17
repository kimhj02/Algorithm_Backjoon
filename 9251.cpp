#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string first_char; //첫번째 문자열
    string second_char; //두번째 문자열
    cin>>first_char>>second_char; //입력

    // 2차원 DP 벡터 생성 (LCS 길이 저장)
    vector<vector<int>> dp(first_char.size() + 1, vector<int>(second_char.size() + 1, 0));
    // first_char.size()+1 X second_char.size()+1 크기 2차원 dp를 0으로 초기화
    // 두 문자열의 길이는 다를 수 있으므로 각 문자열 길이에 +1 해줌

    //이제 반복문을 통해 dp 벡터를 채워보자
    //이중 반복문을 통해 각각의 문자를 비교
    for (int i = 1; i <= first_char.size(); i++) {
        for (int j = 1; j <= second_char.size(); j++) {
            //만약 문자가 같다면, LCS 길이 1 증가
            if (first_char[i - 1] == second_char[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; // 대각선 값 + 1
            } else {
                //다르다면 이전까지 중 큰 값을 선택
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    //최종 LCS 길이는 dp의 마지막 값
    cout << dp[first_char.size()][second_char.size()] << endl;
    return 0;
}