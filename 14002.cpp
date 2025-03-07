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

    vector<int> lis(arr_num, 1);
    vector<vector<int>> matrix(arr_num); //증가하는 수열을 저장하기 위한 2차원 벡터
    int max_length = 0; //최대 길이 저장용
    int max_index = 0; //최대 길이를 가지는 i값 저장용 (matrix에서 찾을거임)

    for (int i = 0; i < arr_num; i++) {
        matrix[i].push_back(arr[i]); //자기자신 넣기

        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && lis[i] < lis[j] + 1) { //이전 값 중 작은 갓들 확인
                lis[i] = lis[j] + 1; //lis[i] 업데이트
                matrix[i] = matrix[j]; //기존 matrix복사 후
                matrix[i].push_back(arr[i]); //추가
            }
        }

        if (max_length < lis[i]) { //가장 긴 수열 찾기
            max_length = lis[i];
            max_index = i;
        }
    }

    cout << max_length << endl; //길이 출력
    for (int i : matrix[max_index]) {  //수열 출력
        cout << i << " ";
    }
    return 0;
}