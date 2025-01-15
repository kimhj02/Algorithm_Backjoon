#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    int N;
    ll L, R, X;
    cin >> N >> L >> R >> X;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int count = 0;

    for (int mask = 0; mask < (1 << N); mask++) {
        ll sum = 0;
        ll minVal = 9223372036854775807;
        ll maxVal = 0;
        int selected = 0;

        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) { //특정 문제 포함 여부 확인
                sum += arr[i];
                minVal = min(minVal, (ll)arr[i]);
                maxVal = max(maxVal, (ll)arr[i]);
                selected++;
            }
        }
//1
        if (selected >= 2 && L <= sum && sum <= R && (maxVal - minVal) >= X) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}


//문제 개수 N, 난이도 최저 N, 난이도 최대 R, 가장 어려운 문제와 가장 쉬운 문제의 난이도 차의 최소 X(이것보다 크거나 같아야함)
//문제는 2개 이상 골라야 함

//입력 첫재줄 : N L R X 가 주어짐
//입력 둘째줄 : 문제의 난이도가 주어짐

//출력 : 캠프에 사용할 문제를 고르는 방법의 수를 출력

//예제
//3 5 6 1
//1 2 3

//출력
//2

//아이디어1 : 먼저 값들의 조합 중 가장 작은 차이가 나는 조함과 가장 작은 차이가 나는 조합을 정함
//아이디어2 : 비트 마스크를 통해 문제가 선택 되었는지를 확인하자
//아이디어3 : 문제를 선택한 다음, 그 문제의 조합이 조건에 맞으면 count 증가
