#include <iostream>
#include <cmath>  // ceil 함수
using namespace std;

int main() {
  int L, A, B, C, D;
  cin >> L >> A >> B >> C >> D;

  int day_lang = (A + C - 1) / C;  // 올림: ceil(A / C)
  int day_math = (B + D - 1) / D;  // 올림: ceil(B / D)

  int max_day = max(day_lang, day_math);
  cout << L - max_day << endl;

  return 0;
}