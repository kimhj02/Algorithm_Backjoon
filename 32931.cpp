#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int case_num = 0;
    cin >> case_num;
    vector<vector<long long>> arr(2, vector<long long>(case_num + 1));
    vector<vector<long long>> dp(2, vector<long long>(case_num + 1, 0));

    //격자 입력
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= case_num; j++) {
            cin >> arr[i][j];
        }
    }

    //첫번째 열의 위쪽칸
    dp[0][1] = max(arr[0][1], arr[0][1] + arr[1][1]); //현재 위치랑 오른쪽으로 이동이랑 비교
    //첫번째 열의 아래쪽칸
    dp[1][1] = arr[0][1] + arr[1][1]; //위에서 아래로 내려온 값

    for (int j = 2; j <= case_num; j++) {
        //위쪽칸
        dp[0][j] = max({dp[0][j - 1] + arr[0][j], //오른쪽으로만 이동
                       dp[0][j - 1] + arr[0][j] + arr[1][j], //위쪽칸에서 아래로 이동
                       dp[1][j - 1] + arr[0][j] + arr[1][j]}); //아래에서 위로 올라감
        //아래쪽칸
        dp[1][j] = max({dp[1][j - 1] + arr[1][j], //오른쪽으로만 이동
                       dp[1][j - 1] + arr[0][j] + arr[1][j], //아래쪽칸에서 위로 이동
                       dp[0][j - 1] + arr[0][j] + arr[1][j]}); //위쪽칸에서 아래로 이동
    }

    cout << dp[1][case_num] << endl; //해당 위치 출력
    return 0;
}