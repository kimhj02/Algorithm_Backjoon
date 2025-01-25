#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long find_max_length(long long low, long long high, const vector<int>& have_line_length, int require_line) {
    long long result = 0; // 최대 길이를 저장할 변수

    while (low <= high) {
        long long mid = (low + high) / 2;
        long long count = 0;

        // mid 길이로 랜선을 자를 때 만들 수 있는 랜선 개수 계산
        for (int length : have_line_length) {
            count += length / mid;
        }

        if (count >= require_line) {
            // 랜선 개수가 충분한 경우, 더 긴 길이도 가능할지 확인
            result = mid;  // 최대 길이 갱신
            low = mid + 1; // 더 큰 범위를 탐색
        } else {
            // 랜선 개수가 부족한 경우, 더 짧은 길이를 탐색
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    int have_line, require_line;
    vector<int> have_line_length;

    // 입력받기
    cin >> have_line >> require_line;
    have_line_length.resize(have_line);

    for (int i = 0; i < have_line; i++) {
        cin >> have_line_length[i];
    }

    // 이분 탐색 범위 설정
    long long low = 1;                          // 최소 랜선 길이
    long long high = *max_element(have_line_length.begin(), have_line_length.end());   // 가장 긴 랜선 길이

    // 최대 랜선 길이 찾기
    long long max_length = find_max_length(low, high, have_line_length, require_line);

    // 결과 출력
    cout << max_length << endl;

    return 0;
}