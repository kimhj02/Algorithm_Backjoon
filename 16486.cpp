//
// Created by 김현진 on 25. 5. 22.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int d1, d2;
  cin >> d1 >> d2;
  long double result = 2 * d1 +2 * 3.141592 * d2;
  printf("%0.10Lf\n", result);
  return 0;
}