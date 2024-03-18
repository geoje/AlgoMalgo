#include <cstdio> // For Test
#include <iostream>
using namespace std;

// dp[n번째][n번째 색][0번째 색]
int n, rgb[1001][3], dp[1001][3][3];

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
    fill_n(&dp[0][0][0], (n + 1) * 3 * 3, 1e6);

    /* Process */
    // 1
    // 0번쨰 l색
    for (int l = 0; l < 3; l++)
        dp[1][l][l] = rgb[1][l];

    //2
    // 2번째 j색, 0번째 l색
    for (int j = 0; j < 3; j++)
        for (int l = 0; l < 3; l++)
            if (j != l)
                dp[2][j][l] = rgb[2][j] + dp[1][l][l];

    // 3 ~ n-1
    // i번째에 j색, i-1번쨰 k색, 0번쨰 l색
    for (int i = 3; i < n; i++)
        for (int j = 0; j < 3; j++)
            for (int l = 0; l < 3; l++)
            {
                for (int k = 0; k < 3; k++)
                    if (j != k)
                        dp[i][j][l] = min(dp[i][j][l], dp[i - 1][k][l]);
                dp[i][j][l] += rgb[i][j];
            }

    // n
    // n번째에 j색, i-1번쨰 k색, 0번쨰 l색
    int ans = 1e6;
    for (int j = 0; j < 3; j++)
        for (int l = 0; l < 3; l++)
            for (int k = 0; k < 3; k++)
                if (j != k && j != l)
                {
                    dp[n][j][l] = rgb[n][j] + dp[n - 1][k][l];
                    if (dp[n][j][l] < ans)
                        ans = dp[n][j][l];
                }

    /* Output */
    // for (int i = 1; i <= 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //         for (int k = 0; k < 3; k++)
    //             cout << i << ' ' << j << ' ' << k << " : " << dp[i][j][k] << '\n';
    //     cout << '\n';
    // }
    cout << ans << '\n';
    return 0;
}