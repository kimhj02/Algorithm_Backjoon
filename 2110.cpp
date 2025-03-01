#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 공유기를 mid 거리 이상으로 설치할 수 있는지 확인
bool canInstall(int mid, vector<int>& v, int C) {
    int count = 1; // 첫 번째 집에 공유기 설치
    int last = v[0]; // 가장 최근에 공유기를 설치한 위치

    for (int i = 1; i < v.size(); i++) {
        if (v[i] - last >= mid) { // mid 거리 이상이면 공유기 설치
            count++;
            last = v[i];
        }
    }
    return count >= C; // C개 이상의 공유기를 설치할 수 있는지 확인ㅁ
}

int binary_search(int start, int end, vector<int>& v, int C) {
    int result = 0; //최댓값

    while (start <= end) {
        int mid = (start + end) / 2;

        if (canInstall(mid, v, C)) { // 공유기를 mid 거리 이상으로 설치 가능하면
            result = mid; // 최댓값 업데이트
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, C; // 집의 개수, 공유기의 개수
    cin >> N >> C;

    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end()); // 정렬

    int low = 1; // 최소 거리
    int high = v[N - 1] - v[0]; // 최대 거리
    int answer = binary_search(low, high, v, C);

    cout << answer << endl;
    return 0;
}

//N개의 수직선 위에 집이 존재
//각 지베 좌표는 x1,x2,x3 ...
//와이파이를 어디서든 사용하기 위해 공유기를 c개 설치
//한 집에는 공유기 하나만 설치 가능
//가장 인접한 두 공유기 사이의 거리를 가능한 크게 설치
//c개의 공유기를 n개의 집에 적당히 설치해, 가장 인접한 두 공유기 사이의 거리를 최대로 하는 프로그램 작성