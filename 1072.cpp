#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long total_game_num, win_game_num;
    cin >> total_game_num >> win_game_num;

    int current_rate = (win_game_num * 100) / total_game_num;

    // 승률이 99% 이상이면 더 이상 증가할 수 없음
    if (current_rate >= 99) {
        cout << -1 << endl;
        return 0;
    }

    long long left = 1, right = 1000000000, answer = -1;

    while (left <= right) {
        long long mid = (left + right) / 2;
        int new_rate = ((win_game_num + mid) * 100) / (total_game_num + mid);

        if (new_rate > current_rate) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << endl;
    return 0;
}