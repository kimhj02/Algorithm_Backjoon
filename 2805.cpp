#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int tree_num, div_tree_num;
    cin >> tree_num >> div_tree_num;

    vector<int> tree_arr(tree_num);
    for (int i = 0; i < tree_num; i++) {
        cin >> tree_arr[i];
    }

    sort(tree_arr.begin(), tree_arr.end()); // 오름차순 정렬

    int start = 0, end = tree_arr[tree_num - 1]; // 절단기 높이 범위
    int result = 0;

    while (start <= end) {
        int mid = (start + end) / 2;
        long long sum = 0;

        for (int i = 0; i < tree_num; i++) {
            if (tree_arr[i] > mid) {
                sum += tree_arr[i] - mid;
            }
        }

        if (sum >= div_tree_num) {
            result = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << result << endl;

    return 0;
}