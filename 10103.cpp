//
// Created by 김현진 on 25. 4. 29.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int test_case = 0;
  int chang_score = 100, sang_score = 100;
  cin >> test_case;
  for(int i = 0; i < test_case; i++) {
    int n1, n2;
    cin >> n1 >> n2;
    if (n1 > n2){
      sang_score -= n1;
    }else if (n1 < n2){
      chang_score -= n2;
    }
  }
  cout << chang_score << endl;
  cout << sang_score << endl;
  return 0;
}