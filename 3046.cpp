//
// Created by 김현진 on 2025. 4. 11..
//
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int R1, average;
  cin >> R1 >> average;
  int R2 = 2 * average - R1;
  cout << R2 << endl;
  return 0;
}

//(R1 + R2) / 2 = av
// R1 + R2 = 2av
// R2 = 2av - R1