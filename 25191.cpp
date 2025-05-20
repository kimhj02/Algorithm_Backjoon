//
// Created by 김현진 on 25. 5. 20.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int chicken_num = 0, coke_num = 0, beer_num = 0;
  cin >> chicken_num;
  cin >> coke_num >> beer_num;
  int count = 0;

  while(chicken_num > 0) {
    if(coke_num >= 2 && chicken_num >= 1) {
      chicken_num--;
      coke_num-=2;
      count++;
    }
    if(beer_num >= 1 && chicken_num >= 1) {
      chicken_num--;
      beer_num--;
      count++;
    }
    if (coke_num < 2 && beer_num < 1) break; //음료가 둘 다 없으면 끝
  }
  cout << count << endl;
  return 0;
}