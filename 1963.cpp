#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

vector<bool> is_prime(10000, true); // 4자리 수의 소수 여부 저장

void get_primes() { //에라스토테네스의 체 구하기
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < 10000; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < 10000; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

vector<int> get_next(int num) {
    vector<int> result;
    string s = to_string(num);

    for (int i = 0; i < 4; i++) {
        char original = s[i];
        for (char c = '0'; c <= '9'; c++) {
            if (c == original) continue;
            s[i] = c;
            int next = stoi(s);
            if (next >= 1000 && is_prime[next]) {
                result.push_back(next);
            }
        }
        s[i] = original; // 원상복구
    }
    return result;
}

int bfs(int start, int end) {
    queue<pair<int, int>> q;
    vector<bool> visited(10000, false); //방문 벡터(사용 헀음)
    q.push({start, 0}); //시작
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (current == end) return steps; //결과값에 맞으면

        for (int next : get_next(current)) {
            if (!visited[next]) {
                visited[next] = true;
                q.push({next, steps + 1});
            }
        }
    }

    return -1; // 안되면
}

int main() {
    int test_case;
    cin >> test_case;

    get_primes(); //소수 미리 구하기

    for (int i = 0; i < test_case; i++) {
        int start, end;
        cin >> start >> end;

        int result = bfs(start, end);
        if (result == -1)
            cout << "Impossible" << endl;
        else
            cout << result << endl;
    }

    return 0;
}