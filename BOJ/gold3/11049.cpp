// #include <cstdio> // For Test
#include <iostream>
using namespace std;

const long long INF = 2147483647;
long long n, r[501], c[501], dp[501][501] = {0};

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> r[i] >> c[i];

    /* Process */
    // Recursive Property
    for (int i = n - 1; i >= 1; i--)
        for (int j = i + 1; j <= n; j++)
        {
            dp[i][j] = INF;
            for (int k = i; k <= j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + (r[i] * c[k] * c[j]));
        }

    /* Output */
    cout << dp[1][n] << '\n';

    // Debug Output
    // cout << '\n';
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //         cout << dp[i][j] << "\t";
    //     cout << '\n';
    // }
    return 0;
}