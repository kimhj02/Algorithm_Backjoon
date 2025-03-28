#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct person {
    int low = 0;
    int high = 0;
};

bool compare(person p1, person p2) {
    return p1.low > p2.low; //내림차순
}

int main() {
    int person_num = 0, total = 0;
    cin >> person_num >> total;
    vector<person> persons(person_num);

    for (int i = 0; i < person_num; i++) { //주량 최소 최대치 입력(이상 이하임)
        cin >> persons[i].low >> persons[i].high;
    }

    sort(persons.begin(), persons.end(), compare);//낮은것 중에 높은것을 찾자
    int a = persons[0].low; //낮는것 중에 높은것
    int temp_total = 0;
    for (int i = 0; i < person_num; i++) {
        temp_total += persons[i].low;
    }

    //선처리
    if (temp_total > total) {
        cout << -1 << endl;
        return 0;
    }

    //s를 처음부터 구하지 말고, 밑에서 부터 값을 증가시켜가며 total을 맞춘 후에 그중에 가장 큰 값을 s로 하자
    int left = a; // a 이상부터 탐색 시작
    int right = 1e9;
    int answer = -1;

    while (left <= right) {
        int mid = (left + right) / 2; // 현재 시도하는 S
        int current_total = 0;

        for (int i = 0; i < person_num; i++) {
            // 각 사람에게 줄 수 있는 술: low ~ min(high, mid)
            current_total += min(persons[i].high, mid);
        }

        if (current_total >= total) {
            answer = mid; // 가능한 경우, 더 작은 S를 탐색
            right = mid - 1;
        } else {
            left = mid + 1; // 총량이 부족하므로 더 큰 S 필요
        }
    }

    cout << answer << endl;
    return 0;
}

//각 사람들에게 기분 좋은 정도와 힘든 정보 입력
//기분 좋지 않은 정도, 죽는 정도
//술 배분

//T 이상의 수릉ㄹ 팔아야 예약 잡을 수 있음
//정확히 T의 술을 결제함

//S 이하의 술만 주려고 함
//모든 사람이 자기 주량의 술을 받으면서
//총합이 정확히 T가 되고
//어떤 사람도 S를 초과하는 술을 받지 않을 수 있는 S를 구하는 문제

//S가 여러개라면 가장 작은 값 출력