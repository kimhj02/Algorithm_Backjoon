//
// Created by 김현진 on 25. 5. 16.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int test_case = 0; // 전깃줄 개수
  cin >> test_case;
  vector<pair<int, int>> wires(test_case);

  for(int i = 0; i < test_case; i++) {
    int start, end;
    cin >> start >> end;
    wires[i] = {start, end}; // A 전봇대와 B 전봇대 연결
  }

  sort(wires.begin(), wires.end());

  vector<int> dp(test_case, 1);
  for (int i = 1; i < test_case; i++) {
    for (int j = 0; j < i; j++) {
      if (wires[j].second < wires[i].second) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  int max_lis = *max_element(dp.begin(), dp.end());

  cout << test_case - max_lis << endl;

  return 0;
}