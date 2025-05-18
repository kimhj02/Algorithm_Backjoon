//
// Created by 김현진 on 25. 5. 18.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int test_case = 0;
    cin >> test_case;
    for(int i = 0; i < test_case; i++) {
      int total = 0;
      int min_val = 2147483647;
      for(int j = 0; j < 7; j++){
        int n = 0;
        cin >> n;
        if(n % 2 == 0){
          total += n;
          min_val = min(min_val, n);
        }
      }
      cout << total << " "<< min_val << endl;
    }
    return 0;
}