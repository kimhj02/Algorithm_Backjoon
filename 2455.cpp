#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int total = 0;
    int max_num = 0;
    for (int i = 0; i < 4; i++) {
        int out, in;
        cin >> out >> in; //나간 사람 들어온 사람
        total -= out;
        total += in;
        max_num = max(max_num, total);
    }
    cout << max_num << endl;
    return 0;
}