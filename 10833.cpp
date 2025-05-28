//
// Created by 김현진 on 25. 5. 28.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int case_num = 0;
  cin >> case_num;
  int count = 0;
  for (int i = 0; i < case_num; i++) {
    int student_num = 0, apple_num = 0;
    cin >> student_num >> apple_num;
    count += apple_num % student_num;
  }
  cout << count << endl;
  return 0;
}