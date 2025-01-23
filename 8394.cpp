#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr(10000000,0);
    int num;
    cin >> num;

    arr[0] = 1;
    arr[1] = 2;

    for (int i = 2; i < num+1; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    cout << arr[num-1] % 10;
    return 0;
}