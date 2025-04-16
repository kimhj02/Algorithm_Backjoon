//
// Created by 김현진 on 2025. 4. 16..
//
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int low_burger = 2000;
  int low_sider = 2000;
  for(int i = 0; i < 3; i++){
    int burger;
    cin >> burger;
    if(burger < low_burger){
      low_burger = burger;
    }
    }
    for(int i = 0; i < 2; i++){
      int sider;
      cin >> sider;
      if(sider < low_sider){
        low_sider = sider;
      }
      }
  cout << low_burger + low_sider - 50 << endl;
  return 0;
}