//
// Created by 김현진 on 25. 5. 21.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int S, K, H;
    cin >> S >> K >> H;
    int total = S + K + H;
    if(total >= 100) cout << "OK";
    else{
      int min_val = min(S,K);
      min_val = min(min_val,H);
      if (min_val == S) {
          cout << "Soongsil";
      } else if (min_val == K) {
          cout << "Korea";
      } else if (min_val == H) {
          cout << "Hanyang";
      }
    }
    return 0;
}