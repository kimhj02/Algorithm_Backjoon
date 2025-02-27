#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct study { //구조체 정의
    int start_time;
    int end_time;
};

bool compare(study a, study b) { //시작 시간 기준으로 정렬
    return a.start_time < b.start_time;
}

int main() {
    int test_case = 0;
    cin >> test_case;

    vector<study> studies(test_case);

    for (int i = 0; i < test_case; i++) { //입력
        cin >> studies[i].start_time >> studies[i].end_time;
    }

    sort(studies.begin(), studies.end(), compare); //시작시간 기준으로 정의

    priority_queue<int, vector<int>, greater<int>> pq; //최소 힙으로 구성

    pq.push(studies[0].end_time);

    for (int i = 1; i < test_case; i++) {
        if (pq.top() <= studies[i].start_time) { //가장 빨리 끝나는 강의의 종료 시간이랑 시작 시간이랑 연결된다면
            pq.pop(); //꺼내고 종료시간 업데이트
        }
        pq.push(studies[i].end_time); //연결된 마지막 시간 push
        //연결 되어 있지 않다면 그냥 push 되어 길이가 증가
    }

    cout << pq.size() << endl; //크기 출력

    return 0;
}

//예시
//1,3 2,4 3,5 라면
//sort로 시작 시간 기준 1,3 2,4 3,5 로 정렬
//처음 종료시간 push, [3]
//다음 (2,4)의 경우 시작 시간이 종료시간 이전이므로 pop 하지 않고 push [3,4]
//다음 (3,5)의 경우 시작 시간이 종료시간과 같으므로 pop 하면 [4]
//이후 push하면 [4,5] 가 됨
//길이는 2