#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;

    vector<long long> dp(N + 1, 0);
    dp[0] = 1;
    dp[1] = 3;

    for (int i = 2; i <= N; ++i) {
        dp[i] = (dp[i-1] * 2 + dp[i-2] * 2) % MOD;
    }

    cout << dp[N] << endl;
    return 0;
}

//학생은 총 2n 명이 있고, 한 줄에 두명씩 짝을 지어 앞뒤로 총 n줄로 앉아 있음
//학생 몇몇을 불러 풀이를 알려주면, 자리로 돌아가서 짝꿍에게 풀이를 전달해 줄 수 있음

//이 때, 모든 학생이 현이 또는 짝꿀에게 풀이를 들어야 하며, 연속된 두 줄 중 적어도 한 줄에는 짝꿍에게의 풀이 전달이 일어나야 함
//이 조건을 만족하도록 현이가 학생을 부를 수 있는 경우의 수는 몇가지 인지 구해보자. 값이 너무 커질 수 있으므로
//10^9 + 7 로 나눈 나머지를 출력

//ex1) 입력 1 -> 출력 3
//학생이 2명, 한줄에 2명씩 1줄, 그렇다면 한명한테 전달하는 경우 2, 둘 다 한테 하는 경우 1 = 총 3가지

//ex2) 입력 2 -> 출력 8
//학생이 4명, 사람을 1,2,3,4라고 하면, 무조건 전달 방식이 하나 있어야 하므로, 최대 3명 선택
//3 명 선택하는 경우 4 , 2명 선택하는 경우 4 = 8

//학생 6명, 1,2,3,4,5,6 이라고 하면
//경우의 수 1 : 3줄 다 전달하는 경우 :
//2c1 2c1 2c1 = 8
//경우의 수 2 : 2줄만 단절하는 경우
// 3c2 * 4 = 12
//경우의 수 3 : 1줄만 전달하는 경우
// 1 * 2 = 2


//dp[n] = 2 * dp[n-1] + dp[n-2]

//dp[1] = 3 (학생 2명)
//dp[2] = dp[1] + dp[1] + 2 = 8 (학생 4명)
//dp[3] = 2 * dp[1] + 2 * dp[2] = (22)이 나와야 함