#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cal_time(int h, int m, int s) {
  return h * 3600 + m * 60 + s;
}

void print_work_time(int start_h, int start_m, int start_s,
                     int end_h, int end_m, int end_s) {
  int start = cal_time(start_h, start_m, start_s);
  int end = cal_time(end_h, end_m, end_s);
  int diff = end - start;

  int h = diff / 3600;
  diff %= 3600;
  int m = diff / 60;
  int s = diff % 60;
  cout << h << " " << m << " " << s << endl;
}

int main() {
  for (int i = 0; i < 3; ++i) {
    int a_h, a_m, a_s;
    int b_h, b_m, b_s;
    cin >> a_h >> a_m >> a_s >> b_h >> b_m >> b_s;
    print_work_time(a_h, a_m, a_s, b_h, b_m, b_s);
  }
  return 0;
}