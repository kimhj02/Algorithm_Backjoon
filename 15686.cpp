#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N, M; // 도시의 크기(N×N)와 남길 치킨집의 개수 M
vector<pair<int, int>> houses, chickens; // 집과 치킨집의 위치를 저장하는 벡터
vector<vector<int>> city; // 도시의 상태를 저장하는 2D 벡터
vector<int> selected; // 선택된 치킨집의 인덱스를 저장하는 벡터
int min_chicken_distance = INT_MAX; // 최소 치킨 거리 (최소화할 값)

int cal_distance() {
    int total_distance = 0;

    // 모든 집에 대해 가장 가까운 치킨집까지의 거리 계산
    for (auto house : houses) {
        int dx = house.first;
        int dy = house.second;
        int min_distance = INT_MAX;

        // 현재 선택된 치킨집 중에서 가장 가까운 치킨집 찾기
        for (int idx : selected) {
            int cx = chickens[idx].first;
            int cy = chickens[idx].second;
            min_distance = min(min_distance, abs(dx - cx) + abs(dy - cy));
        }

        total_distance += min_distance; // 각 집의 치킨 거리를 더함
    }

    return total_distance;
}

void select_chicken(int start, int count) {
    if (count == M) { // M개의 치킨집을 선택하면 치킨 거리 계산
        min_chicken_distance = min(min_chicken_distance, cal_distance());
        return;
    }

    for (int i = start; i < chickens.size(); i++) {
        selected.push_back(i); // 치킨집 선택
        select_chicken(i + 1, count + 1); // 다음 치킨집 선택 (백트래킹)
        selected.pop_back(); // 선택 취소 (백트래킹)
    }
}

int main() {
    cin >> N >> M;
    city.resize(N, vector<int>(N)); // N×N 크기의 도시 행렬 초기화

    // 도시 정보 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> city[i][j];
            if (city[i][j] == 1) houses.push_back({i, j}); // 집 위치 저장
            else if (city[i][j] == 2) chickens.push_back({i, j}); // 치킨집 위치 저장
        }
    }

    select_chicken(0, 0); // 치킨집 선택 시작
    cout << min_chicken_distance << endl; // 최소 치킨 거리 출력

    return 0;
}