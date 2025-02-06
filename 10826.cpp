#include <iostream>
#include <vector>
using namespace std;

string big(string a, string b) {
    string result = "";
    int carry = 0;

    while (a.length() < b.length()) a = "0" + a;
    while (b.length() < a.length()) b = "0" + b;

    for (int i = a.length() - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result = char((sum % 10) + '0') + result;
        carry = sum / 10;
    }

    if (carry) result = "1" + result;
    
    return result;
}

int main() {
    int num;
    cin >> num;

    vector<string> fibo(num + 1);
    fibo[0] = "0";
    if (num > 0) fibo[1] = "1";

    for (int i = 2; i <= num; i++) {
        fibo[i] = big(fibo[i - 1], fibo[i - 2]);
    }

    cout << fibo[num] << endl;
    return 0;
}