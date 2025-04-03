#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int test_case = 0; //test case
    cin >> test_case; //input
    for (int i = 0; i < test_case; i++) { //tset case loop
        int min_time = 0; //최소 시간
        int max_time = 0; //최대 시간
        int length = 0, ant_num = 0;
        cin >> length >> ant_num;
        vector<int> stick(length, -1); //0부터 length -1까지 길이 length

        for (int j = 0; j < ant_num; j++) {
            int x = 0;
            cin >> x; //입력

            //최소 시간: 각 개미가 가까운 끝으로 가는 시간 중 최대값
            int min_dist = min(x, length - x); //왼쪽 또는 오른쪽 끝까지 거리 중 작은 값
            min_time = max(min_time, min_dist); //그 중 최대값이 최소 시간

            //최대 시간: 각 개미가 먼 끝까지 가는 시간 중 최대값
            int max_dist = max(x, length - x); //왼쪽 또는 오른쪽 끝까지 거리 중 큰 값
            max_time = max(max_time, max_dist); //그 중 최대값이 최대 시간
        }

        cout << min_time << " " << max_time << endl; //출력
    }
    return 0;
}

//개미 여러 마리가 길이가 lcm인 막대 위에 있음
//각 개미의 이동 속도는 모두 일정, 1cm/s
//개미가 막대기의 마지막까지 걸어간다면, 개미는 그 즉시 떨어짐
//두 개미가 만나면 방향을 반대로 바꾸어 거렁감

//가장 처음에 막대 상에서 개미의 위치를 알 고 있음
//하지만 개미가 어느 방향으로 가는지는 알 수 없음
//이 때, 모든 개미가 따으로 떨어질 때까지 가능한 시간 중 가장 빠른 시간과 느린 시간을 구하라

//입력 : 테스트 케이스, 막대의 길이와 개미의 수 n, 개미의 초기 위치
//개미의 위치는 막대 왼쪽 끝에서부터 떨어진 거리임