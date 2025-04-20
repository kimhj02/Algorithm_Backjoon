//
// Created by 김현진 on 25. 4. 20.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
      int num1, num2;
      cin >> num1 >> num2;
      cout << "Case " << i+1 << ": " << num1+num2 << endl;
    }
    return 0;
}