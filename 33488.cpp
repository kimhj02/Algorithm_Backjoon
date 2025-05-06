#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// 소수 판별 함수
bool is_prime(int n) {
  if (n < 2) return false;
  for (int i = 2; i <= sqrt(n); ++i)
    if (n % i == 0) return false;
  return true;
}

// 아름다운 수열인지 확인하는 함수
bool is_beautiful(const vector<int>& seq, const vector<bool>& prime_dist, const vector<bool>& prime_diff) {
  int n = seq.size();
  for (int d = 1; d < n; ++d) {
    if (!prime_dist[d]) continue;
    for (int i = 0; i + d < n; ++i) {
      int diff = abs(seq[i] - seq[i + d]);
      if (prime_diff[diff]) return false;
    }
  }
  return true;
}

int main() {
  int T;
  cin >> T;

  // 미리 소수 여부를 계산
  vector<bool> prime(2001, false);
  for (int i = 2; i <= 2000; ++i)
    prime[i] = is_prime(i);

  while (T--) {
    int n;
    cin >> n;

    vector<int> seq(n);
    for (int i = 0; i < n; ++i)
      seq[i] = i + 1;

    bool found = false;
    do {
      if (is_beautiful(seq, prime, prime)) {
        cout << "Yes\n";
        for (int i = 0; i < n; ++i)
          cout << seq[i] << " ";
        cout << "\n";
        found = true;
        break;
      }
    } while (next_permutation(seq.begin(), seq.end()));

    if (!found)
      cout << "No\n";
  }

  return 0;
}