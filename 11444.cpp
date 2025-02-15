#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

#define MOD 1000000007

void matrix_mux(ll first_vec[2][2],ll second_vec[2][2]) { //2*2 행렬과 2*2 행렬을 곱해보자
    ll result[2][2];
    result[0][0] = (first_vec[0][0] * second_vec[0][0] + first_vec[0][1] * second_vec[1][0]) % MOD; //0,0
    result[0][1] = (first_vec[0][0] * second_vec[0][1] + first_vec[0][1] * second_vec[1][1]) % MOD; //0,1
    result[1][0] = (first_vec[1][0] * second_vec[0][0] + first_vec[1][1] * second_vec[1][0]) % MOD; //1,0
    result[1][1] = (first_vec[1][0] * second_vec[0][1] + first_vec[1][1] * second_vec[1][1]) % MOD; //1,1

    first_vec[0][0] = result[0][0];
    first_vec[0][1] = result[0][1];
    first_vec[1][0] = result[1][0];
    first_vec[1][1] = result[1][1];
}

//이제 행렬 거듭제곱을 사용해보자
void matrix_ex(ll vec[2][2], ll num) {
    if (num <= 1) return;

    ll result[2][2] = {{1,1},{1,0}};

    //일단 반으로 나누자
    matrix_ex(vec, num/2);
    matrix_mux(vec, vec); //짝수라면

    if (num % 2 == 1) { //홀수라면
        matrix_mux(vec, result);
    }
}


int main() {
    ll n;
    cin >> n;

    if (n == 0) { //초기조건
        cout << 0 << endl;
        return 0;
    }
    if (n == 1) { //초기조건
        cout << 1 << endl;
        return 0;
    }

    ll matrix[2][2] = {{1, 1}, {1, 0}}; //행렬을 사용하기 위한 행렬
    matrix_ex(matrix, n - 1);

    cout << matrix[0][0] << endl; // F(n) 값 출력
    return 0;
}

//1. 피보나치 수 기본 개념 : f[n] = f[n-1] + f[n-2]
//2. 힌트를 보면 피보나치 수열을 행렬을 이용한 피보나치 계산을 이용하면 할 수 있다고 한다
//3. 또한 행렬 거듭제곱을 분할 정복으로 사용해야 한다고 한다
//4. 마지막으로 수가 너무 커지기 때문에 모듈러 연산ㅇ르 통해 1000000007로 나눈 나머지를 출력하애하므로, mod 연산을 적용해야 함

//자 이제 1단계부터 하나하나 해보자
//1. 행렬을 통해 피보나치 계산을 한번 해보자.
//일단 행렬 곱을 구하는 방법을 알아보자
//2 * 2 와 2 * 2 행렬을 곱해보자 -> 하면 2*2행렬이 나옴
//3. 행렬 거듭제곱을 분할 정복으로 사용해보자