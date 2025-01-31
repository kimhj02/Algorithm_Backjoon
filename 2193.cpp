#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int case_num = 0;
    cin >> case_num;
    vector <long long> dp;
    dp.resize(case_num);

    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < case_num; i++) {
        dp[i] = dp[i - 2] + dp[i - 1];
    }
    cout <<dp[case_num - 1] << endl;
}

//1. 0으로 시작하지 않음
//2. 이친수에서 1이 두번 연속으로 나타나지 않음
//예 : 1, 10, 100, 101, 1000, 1001 등이 이친수임
//n이 주어졌을 때, n자리 이친수의 개수를 구하는 문제

//입력 : n
//출력 : n자리 이친수의 개수

//n = 1 : 1 : 1
//n = 2 : 10 : 1
//n = 3 : 100 101 : 2
//n = 4 : 1000 1010 1001 : 3
//n = 5 : 10000 10100 10010 10001 10101 : 5
//n = 6 : 100000 101000 100100 100010 100001 101010 100101 : 8