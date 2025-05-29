//
// Created by 김현진 on 25. 5. 29.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;
        cout << (2 - V + E) << endl;
    }
    return 0;
}