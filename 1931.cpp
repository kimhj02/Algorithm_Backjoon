#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct meeting {
    int start_time;
    int end_time;
};

bool compare(meeting a, meeting b) {
    if (a.end_time == b.end_time) return a.start_time < b.start_time;
    return a.end_time < b.end_time;
}

int main() {
    int test_case = 0;
    cin >> test_case; // 회의 개수
    vector<meeting> meetings(test_case);

    for (int i = 0; i < test_case; i++) {
        cin >> meetings[i].start_time >> meetings[i].end_time;
    }

    // 종료 시간이 빠른 순서로 정렬
    sort(meetings.begin(), meetings.end(), compare);

    int count = 0; // 최대 배정할 수 있는 회의 개수
    int last_end_time = 0; // 마지막으로 배정한 회의의 종료 시간
    int index = 0;

    while (index < test_case) {
        // 현재 회의가 이전 회의 종료 시간 이후에 시작하면 선택
        if (meetings[index].start_time >= last_end_time) {
            last_end_time = meetings[index].end_time; // 종료 시간 갱신
            count++; // 회의 개수 증가
        }
        index++; // 다음 회의로 이동
    }

    cout << count << endl;
    return 0;
}