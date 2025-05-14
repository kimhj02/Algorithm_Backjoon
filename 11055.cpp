#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i = 0; i < n; i++)
    cin >> arr[i];

  vector<int> dp(n);
  int result = 0;

  for(int i = 0; i < n; i++) {
    dp[i] = arr[i]; // 자기 자신부터 시작
    for(int j = 0; j < i; j++) {
      if(arr[j] < arr[i]) {
        dp[i] = max(dp[i], dp[j] + arr[i]);
      }
    }
    result = max(result, dp[i]);
  }

  cout << result << endl;
  return 0;
}