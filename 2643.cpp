#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//너비 기준 오름차순, 너비가 같다면 높이 기준 오름차순
bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;  // 너비가 같다면 높이 기준 오름차순
    return a.first < b.first;  // 너비 기준 오름차순
}

int main() {
    int case_num = 0;
    cin >> case_num;

    vector<pair<int,int>> rectangle(case_num);

    // 색종이 입력받기 90도 돌리기가 가능
    for (int i = 0; i < case_num; i++) {
        int width, length;
        cin >> width >> length;
        if (width > length) swap(width, length); //세로가 가로보다 크도록 유지
        rectangle[i] = {width, length}; //직사각형 길이 입력
    }

    // 색종이를 정렬
    sort(rectangle.begin(), rectangle.end(), compare);

    vector<int> dp(case_num, 1);

    int max_count = 1;

    for (int i = 1; i < case_num; i++) {
        for (int j = 0; j < i; j++) {
            if (rectangle[j].first <= rectangle[i].first && rectangle[j].second <= rectangle[i].second) { //i 직사각형보다 j 정사각형이 작다면 업데이트
                dp[i] = max(dp[i], dp[j] + 1); //색종이가 개수 따른 최대 개수 업데이트
            }
        }
        max_count = max(max_count, dp[i]); //i 변경에 따른 최대 개수 업데이트
    }

    cout << max_count << endl;
    return 0;
}