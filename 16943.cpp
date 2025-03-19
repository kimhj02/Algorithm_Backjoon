#include <iostream>
#include <vector>
#include <string>
using namespace std;

string A, B;
vector<bool> visited(10);
int max_result = -1;
vector<int> digits;  // A의 숫자 저장

// 백트래킹
void back_track(string cur) {
    if (cur.length() == A.length()) {  // 숫자 완성
        if (cur[0] != '0' && stoi(cur) < stoi(B)) {  // B보다 작은 경우만
            max_result = max(max_result, stoi(cur));
        }
        return;
    }

    for (int i = 0; i < digits.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            back_track(cur + to_string(digits[i]));  // 숫자 추가
            visited[i] = false;  // 백트래킹
        }
    }
}

int main() {
    cin >> A >> B;

    for (char c : A) {
        digits.push_back(c - '0');
    }

    back_track("");

    cout << max_result << endl;
    return 0;
}