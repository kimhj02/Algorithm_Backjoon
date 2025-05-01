//
// Created by 김현진 on 25. 5. 1.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  long long N = 0, M = 0;
  cin >> N >> M;
  long long total = 0;

  for(long long i = 0; i < N; i++) {
    long long num = 0;
    cin >> num;
    total += num;
  }
  total -= N;
  if (M > total) cout << "OUT" << endl;
  else cout << "DIMI" << endl;
  return 0;
}