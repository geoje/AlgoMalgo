#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Input
    int n, value[500][500], dp[500][500] = {0};
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            cin >> value[i][j];

    // Process

    /* Boundary Condition */
    dp[0][0] = value[0][0];
    dp[1][0] = value[1][0] + dp[0][0];
    dp[1][1] = value[1][1] + dp[0][0];

    /* Recursive Property */
    for (int i = 2; i < n; i++)
    {
        dp[i][0] = value[i][0] + dp[i - 1][0];     // 맨 좌측
        dp[i][i] = value[i][i] + dp[i - 1][i - 1]; // 맨 우측
        for (int j = 1; j < i; j++)                // 가운데
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + value[i][j];
    }

    // Output
    n--;
    int ans = 0;
    for (int j = 0; j <= n; j++)
        if (dp[n][j] > ans)
            ans = dp[n][j];
    cout << ans << '\n';
    return 0;
}