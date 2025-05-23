//
// Created by 김현진 on 25. 5. 23.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    //컵 3개를 일렬로 엎어놓음
    //순서대로 1,2,3번
    int case_num = 0;
    cin >> case_num;
    int has_ball = 1;
    for (int i = 0; i < case_num; i++) {
        int change1, change2;
        cin >> change1 >> change2;
        if (change1 == has_ball) {
            has_ball = change2;
        }else if (change2 == has_ball) {
            has_ball = change1;
        }
    }
    cout << has_ball << endl;
    return 0;
}