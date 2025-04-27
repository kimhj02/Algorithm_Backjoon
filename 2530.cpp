//
// Created by 김현진 on 25. 4. 27.
//
#include <iostream>
using namespace std;

int main() {
  int A, B, C;  // 현재 시간 (시, 분, 초)
  int required_time;  // 요리 시간 (초)
  cin >> A >> B >> C;
  cin >> required_time;

  int total_sec = A * 3600 + B * 60 + C + required_time;

  total_sec %= (24 * 3600);  // 24시간을 넘기면 하루로 되돌리기

  int si = total_sec / 3600;
  total_sec %= 3600;
  int bun = total_sec / 60;
  int cho = total_sec % 60;

  cout << si << " " << bun << " " << cho << endl;
}