//
// Created by 김현진 on 25. 4. 30.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int test_cese = 0;
  cin >> test_cese;
  for (int i = 0; i < test_cese; i++) {
    int num = 0;
    cin >> num;
    for(int j = 0; j < num; j++) {
      cout << "=";
    }
    cout << endl;
  }
  return 0;
}