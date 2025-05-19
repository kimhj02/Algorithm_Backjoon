#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int arr[6]; // 국어, 영어, 수학, 과학, 사회, 한국사

    // 점수 입력
    for (int i = 0; i < 6; ++i) {
        cin >> arr[i];
    }

    // 국어~과학 중 상위 3과목 선택
    sort(arr, arr + 4, greater<int>());

    int sum = arr[0] + arr[1] + arr[2];

    // 사회, 한국사 중 높은 점수 선택
    sum += max(arr[4], arr[5]);

    // 출력
    cout << sum << endl;

    return 0;
}