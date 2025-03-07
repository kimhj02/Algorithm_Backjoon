#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int arr_num = 0;
    cin >> arr_num;

    vector<int> arr(arr_num);
    for (int i = 0; i < arr_num; i++) {
        cin >> arr[i];
    }


    vector<int> lis(arr_num, 1); //오른쪽 찾기(초기 1로 초기화)
    for (int i = 0; i < arr_num; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    //1 5 2 1 4 3 4 5 2 1
    //lis = [1,1,1,1,1,1,1,1,1,1]
    // i = 1(5), lis = [1,2,1,1,1,1,1,1,1,1]
    // i = 2(2). lis = [1.2.2.1.1.1.1.1.1.1]
    // i = 3(1). lis = [1,2,2,1,1,1,1,1,1,1]
    // i = 4(4), lis = [1,2,2,1,3,1,1,1,1,1]
    // i = 5(3), lis = [1,2,2,1,3,3,1,1,1,1]
    // i = 6(4), lis = [1,2,2,1,3,3,4,1,1,1]
    // i = 7(5), lis = [1,2,2,1,3,3,4,5,1,1]
    // i = 8(2), lis = [1,2,2,1,3,3,4,5,2,1]
    // i = 9(1), lis = [1,2,2,1,3,3,4,5,2,1]


    vector<int> lds(arr_num, 1); //왼쪽 찾기
    for (int i = arr_num - 1; i >= 0; i--) {
        for (int j = arr_num - 1; j > i; j--) {
            if (arr[j] < arr[i]) {
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }

    int result_num = 0;
    for (int i = 0; i < arr_num; i++) {
        result_num = max(result_num, lis[i] + lds[i] - 1);
    }

    cout << result_num << endl;
    return 0;
}