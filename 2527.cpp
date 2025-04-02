#include <iostream>
using namespace std;

int main() {
    int case_num = 4;
    for (int i = 0; i < case_num; i++) {
        int x1, y1, x2, y2;
        int x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> x3 >> y3 >> x4 >> y4;

        if (x2 < x3 || x4 < x1 || y2 < y3 || y4 < y1) {
            cout << "d" << endl;
        }
        else if ((x2 == x3 && y2 == y3) || (x2 == x3 && y1 == y4) ||
                 (x1 == x4 && y2 == y3) || (x1 == x4 && y1 == y4)) {
            cout << "c" << endl;
                 }
        else if (x2 == x3 || x1 == x4 || y2 == y3 || y1 == y4) {
            cout << "b" << endl;
        }
        else {
            cout << "a" << endl;
        }
    }
    return 0;
}