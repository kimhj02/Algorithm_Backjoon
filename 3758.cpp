#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct team {
    int id;
    int score = 0;                 // 총 점수
    vector<int> problem;           // 문제별 최고 점수
    int submit_num = 0;            // 제출 횟수
    int last_time = 0;             // 마지막 제출 시간
};

bool compare(const team &a, const team &b) {
    if (a.score != b.score)
        return a.score > b.score;
    if (a.submit_num != b.submit_num)
        return a.submit_num < b.submit_num;
    return a.last_time < b.last_time;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int case_num = 0;
    cin >> case_num;

    while (case_num--) {
        int team_num = 0, pro_num = 0, my_id = 0, log_num = 0;
        cin >> team_num >> pro_num >> my_id >> log_num;

        vector<team> teams(team_num + 1); // 팀 ID는 1번부터 시작
        for (int i = 1; i <= team_num; i++) {
            teams[i].id = i;
            teams[i].problem.assign(pro_num + 1, 0);
        }

        for (int time = 1; time <= log_num; time++) {
            int tid, pid, score;
            cin >> tid >> pid >> score;

            // 최고 점수만 반영
            teams[tid].problem[pid] = max(teams[tid].problem[pid], score);
            teams[tid].submit_num++;
            teams[tid].last_time = time;
        }

        // 점수 계산
        for (int i = 1; i <= team_num; i++) {
            int total = 0;
            for (int j = 1; j <= pro_num; j++) {
                total += teams[i].problem[j];
            }
            teams[i].score = total;
        }

        // 정렬
        sort(teams.begin() + 1, teams.end(), compare);

        // 우리 팀 순위 찾기
        for (int i = 1; i <= team_num; i++) {
            if (teams[i].id == my_id) {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}