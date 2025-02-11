#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct candy_data {
    int weight;
    int price;
};

int main() {
    while (true) {
        int candy_num = 0;
        double money = 0.0;
        cin >> candy_num >> money;

        if (candy_num == 0 && money == 0.00) break;

        int change_money = static_cast<int>(round(money * 100)); //소수점 제거 후 정수로 바꿈
        vector<candy_data> candies(candy_num);
        vector<int> dp(change_money + 1, 0); // dp[i]: i원으로 얻을 수 있는 최대 칼로리

        for (int i = 0; i < candy_num; i++) { //입력
            double price;
            cin >> candies[i].weight >> price;
            candies[i].price = static_cast<int>(round(price * 100)); //소수점 제거 후 정수로 바꿈
        }
        for (int i = 0; i < candy_num; i++) {
            int price = candies[i].price;
            int weight = candies[i].weight;
            for (int j = price; j <= change_money; j++) {
                //사탕을 선택하지 않은 경우와, 선택한 경우를 비교해서 더 큰 값 업데이트
                //그럼 점화식 : dp[n] = max(dp[n], dp[n-가격(price)] + 칼로리(weight));
                dp[j] = max(dp[j], dp[j - price] + weight);
            }
        }
        //입력 급액으로 살 수 있는 최대 칼로리 입력
        cout << dp[change_money] << endl;
    }
    return 0;
}
//두 사람이 같은 든을 가지고 가게에 들어가서 사탕을 삼. 이때, 구매한 사탕의 칼로리가 더 큰 사람이 내기에서 이기게 된다

//상근이는 잠시 화장실에 갔다온다는 핑계를 댄 뒤에, 노트북을 열고 사탕 가게 시스템 해킹
//이 시스켐에는 현재 사탕 가게에 있는 사탕의 가격과 칼로리가 모두 등재되어 있음
//각 사타으이 개수는 매우 많기 때문에, 원하는 만큼 구매 가능
//사탕 가게에 있는 모든 사탕의 가격과 칼로리가 주어졌을 때, 칼로리의 합이 가장 크게 되는지를 구하자

//입력 : 사탕의 종류의 수와 상근이가 가지고 이있는 돈의 양, 돈의 양은 상항 소수점 둘쨰자리까지 주어짐
//다음 n개의 줄에는 각 사탕의 칼로시와 가격이 주어짐
//입역의 마지막 줄에는 항상 0 0.00이 주어짐

//출력 : 각 테스트 케이스에 대해서, 상근이가 돈 m을 가지고 구매할 수 있는 가장 높은 칼로리를 출력한다

//입력을 받고 round를 사용해서 반올림해서 정수로 변환해자
//dp 벡터 : i의 금액으로 살 수 있는 최대 칼로리
//입력을 받고 소수점 제거 후 정수로 변환
//점화식 : 구현해야 하는것, i 금액으로 최대치를 사는 것
//업데이트 해보자 : 입력받은 캔디의 가격부터 내가 살 수 있는 최대 금액까지의 dp를 업데이트
//그럼 점화식 : dp[n] = max(dp[n], dp[n-가격(price)] + 칼로리(weight));