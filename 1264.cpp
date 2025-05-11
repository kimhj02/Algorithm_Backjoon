#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  while (true) {
    getline(cin, s);  // 한 줄 전체 입력
    if (s == "#") break;

    int count = 0;
    for (char c : s) {
      c = tolower(c);  // 소문자로 통일해서 비교
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        count++;
      }
    }

    cout << count << endl;
  }
  return 0;
}