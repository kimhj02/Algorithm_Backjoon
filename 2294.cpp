#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int coin_num = 0, cash = 0; //동전의 수, 만들어야 하는 돈
    cin >> coin_num >> cash;//입력

    set<int> coin_set; //중복 방지를 위한 set 사용
    for (int i = 0; i < coin_num; i++) { //입력 받기
        int coin;
        cin >> coin;
        coin_set.insert(coin); //set에 넣음
    }

    vector<int> coins(coin_set.begin(), coin_set.end()); // 중복 제거된 동전 리스트
    vector<int> dp(cash + 1, 1e9); //dp를 목표 금액 크기로 설정
    dp[0] = 0; // 0원을 만들기 위한 동전 개수는 0

    for (int coin : coins) {
        for (int j = coin; j <= cash; j++) {
            dp[j] = min(dp[j], dp[j - coin] + 1);
        }
    }

    if (dp[cash] == 1e9) {
        cout << -1 << endl;
    } else {
        cout << dp[cash] << endl;
    }

    return 0;
}

//n가지 종류의 동전이 있다. 이 동전들을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 그러면서 동전의 개수가 최소
//각각의 동전은 몇 개라도 사용할 수 있음
//입력 : 첫째 줄에 n, k 가 주어짐, 다음 n개의 줄에는 동전의 가치가 주언짐, 동전의 가치는 100,000 보자 작거나 같음
//출력 : 첫째 줄에 사용한 동전의 최소 개수를 출력한다. 불가능하다면 -1 출력

//문제 해결 아이디어 : dp를 써야하는건 알겠는데,