#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long div_search(long long A, long long B, long long C) {
    if (B == 0) return 1;

    long long mid = div_search(A, B / 2, C);
    if (B % 2 == 0) return (mid * mid) % C; //짝수일 때
    else return ((mid * mid) % C * A) % C; //홀수일 떄
}

int main() {
    int first = 0, second = 0, third = 0;
    cin >> first >> second >> third;

    cout << div_search(first, second, third) << endl;
    return 0;
}

//일단 (first * second) % third를 구하는 문제는 맞음
//근데 이제 수가 너무 커져서 어떨게 해결해야 할까
//모듈러 연산을 통해 ((first % third) * (second % third)) % third 로 표현할 수 있음
