#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int DFS_count = 0;
vector<int> arr;
vector<bool> visited; //방문 확인용 vector

void DFS(int i) { //i는 몇번째 돌인지 확인하는 용도
    DFS_count++;
    if (i - arr[i] > 0 && !visited[i-arr[i]]) { //-일 때 유효한 위치인지 확인
        visited[i-arr[i]] = true;
        //cout << i << "에서 출발해서" << arr[i] << "만큼 빼서" << i-arr[i] << "로 DFS" << endl;
        DFS(i - arr[i]);
    }
    if (i + arr[i] <= arr.size() && !visited[i+arr[i]]) { //+일 때 유효한 위치인지 확인
        visited[i+arr[i]] = true;
        //cout << i << "에서 출발해서" << arr[i] << "만큼 더해서" << i+arr[i] << "로 DFS" << endl;
        DFS(i + arr[i]);
    }
}

int main() {
    int case_num = 0,start_point = 0, count = 0;
    cin >> case_num;
    visited.assign(case_num+2, false);//visited 초기화
    arr.assign(case_num+2, 0); //돌다리 초기화

    for (int i = 1; i <= case_num; i++) {
        cin >> arr[i];
    }
    cin >> start_point;
    //방문한 곳을 또 방문할 수 있나?
    DFS(start_point); //시작 지점에서 시작
    visited[start_point] = true; //방문처리

    for (int i = 1; i <= case_num; i++) {
        if (visited[i] == true) { //방문 가능한 돌들의 개수 확인
            //cout << i<< " ";
            count++;
        }
    }
    //cout << DFS_count << endl;
    cout << count<< endl;
    return 0;
}

//n개의 돌이 일렬로 놓여있는 돌다리 존재
//돌다리의 돌에는 숫자가 하나씩 있음
//숫자가 적혀있는 만큼 왼쪽이나 오른쪽으로 이동 가능

//이 돌다리에서 자기가 방문 가능한 돌들의 개수를 알고 싶어함
//방문 가능하다는 것은 현재 위치에서 다른 돌을 적절히 밟아 해당하는 위치로 이동이 가능한 것

//현재 위치가 주어졌을 때, 영우가 방문 가능한 돌들의 개수를 추렭

//입력1 : 돌다리의 개수, 그 위치에서 점프할 수 있는 거리
//입력2 : 출발점

//출력 : 방문 가능한 돌들의 개수