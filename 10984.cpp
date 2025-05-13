//
// Created by 김현진 on 25. 5. 13.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
  int test_case = 0;
  cin >> test_case;
  for(int i = 0; i < test_case; i++) {
    int class_num = 0;
    cin >> class_num;
    float result = 0.0;
    int total_time = 0;
    for(int j = 0; j < class_num; j++) {
      int time = 0;
      float score = 0;
      cin >> time >> score;
      total_time += (int)time;
      result += time * score;
    }
    result /= total_time;
    cout << total_time <<" ";
    printf("%0.1f",floor(result*10)/10);
    cout << endl;
  }
  return 0;
}