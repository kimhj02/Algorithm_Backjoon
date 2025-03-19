#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s;
    string result;
    cin >> s;
    cout << s[0];
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == '-') {
            cout << s[i+1];
            //cout << index << endl; 잘 찾았음
        }
    }
    return 0;
}