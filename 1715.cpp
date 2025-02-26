#include <iostream>
#include <queue>

using namespace std;

int main() {
    int test_case;
    cin >> test_case;

    priority_queue<int, vector<int>, greater<int>> pq; // 최소 힙

    for (int i = 0; i < test_case; i++) {
        int num;
        cin >> num;
        pq.push(num);
    }

    int sum = 0; // 총 비교 횟수

    while (pq.size() > 1) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        int combined = first + second;
        sum += combined;

        pq.push(combined);
    }

    cout << sum << endl;
    return 0;
}