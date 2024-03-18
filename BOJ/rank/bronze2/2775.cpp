#include <cstdio> // For Test
#include <iostream>
using namespace std;

int k, n, dp[15][15];

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Process */
    for (int i = 1; i <= 14; i++)
    {
        dp[i][1] = 1;
        dp[0][i] = i;
    }
    for (int i = 1; i <= 14; i++)
    {
        for (int j = 2; j <= 14; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }

    int t;
    cin >> t;
    while (t--)
    {
        /* Input */
        cin >> k >> n;

        /* Output */
        cout << dp[k][n] << '\n';
    }
    return 0;
}