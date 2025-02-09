#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int test_case;
    cin >> test_case;

    vector<int> arr(test_case);
    for (int i = 0; i < test_case; i++)
    {
        cin >> arr[i];
    }

    if (test_case == 0)
    {
        cout << 0;
        return 0;
    }

    vector<int> dp(test_case, 1);
    int max_len = 1;

    for (int i = 1; i < test_case; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_len = max(max_len, dp[i]);
    }

    cout << max_len;
    return 0;
}
