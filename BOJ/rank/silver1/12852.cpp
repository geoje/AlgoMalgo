#include <cstdio> // For Test
#include <iostream>
using namespace std;

int n, dp[1000001] = {0}, ans[1000001] = {0};

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n;

    /* Process */
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;
        for (int j = 2; j <= 3; j++)
            if (i % j == 0 && dp[i / j] < dp[i])
            {
                dp[i] = dp[i / j] + 1;
                ans[i] = j;
            }
    }

    /* Output */
    cout << dp[n] << '\n'
         << n << ' ';
    while (n > 1)
    {
        if (ans[n])
            n /= ans[n];
        else
            n--;
        cout << n << ' ';
    }
    return 0;
}