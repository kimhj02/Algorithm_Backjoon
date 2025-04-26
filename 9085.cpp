//
// Created by 김현진 on 25. 4. 26.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int test_case = 0;
    cin >> test_case;
    for (int i = 0; i < test_case; i++) {
        int case_num = 0;
        cin >> case_num;
        int total = 0;
        for (int j = 0; j < case_num; j++) {
            int num = 0;
            cin >> num;
            total += num;
        }
        cout << total << endl;
    }
    return 0;
}