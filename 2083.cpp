//
// Created by 김현진 on 25. 6. 3.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    while (true) {
        string s;
        int age, weight;
        cin >> s >> age >> weight;
        if (s == "#" && age == 0 && weight == 0) break;
        if (age > 17 || weight >= 80) {
            cout << s << " "<< "Senior" << endl;
        }else {
            cout << s <<" "<< "Junior" << endl;
        }

    }
    return 0;
}