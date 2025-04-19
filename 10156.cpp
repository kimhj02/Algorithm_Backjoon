//
// Created by 김현진 on 2025. 4. 19..
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  //과자 한개의 가격 K, 사려고 하는 과자의 개수 N, 현재 가지고 있는 돈의 액수 M
  int snack_num, buy_num, had_cash;
  cin >> snack_num >> buy_num >> had_cash;
  int required_cash = snack_num * buy_num - had_cash;
  if ( required_cash > 0 ) cout << required_cash << endl;
  else cout << 0 << endl;
  return 0;

}