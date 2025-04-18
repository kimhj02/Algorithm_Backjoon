//
// Created by 김현진 on 2025. 4. 18..
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int day;
  cin >> day;
  int count = 0;
  for(int i = 0; i < 5; i++){
    int a;
    cin >> a;
    if(a == day) count++;
    }
    cout << count << endl;
    return 0;
}