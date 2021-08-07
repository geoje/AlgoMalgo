// #include <cstdio> // For Test
#include <iostream>
using namespace std;

int n, ans = 0, result, a[1000], dp[2][1000];

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Process
    for (int i = 0; i < n; i++)
    {
        // 순차적 증가 판별
        dp[0][i] = 1;
        for (int j = 0; j < i; j++)
            if (a[j] < a[i] && dp[0][j] >= dp[0][i])
                dp[0][i] = dp[0][j] + 1;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        // 역순 증가 판별 및 정답 도출
        dp[1][i] = 1;
        for (int j = n - 1; j > i; j--)
            if (a[j] < a[i] && dp[1][j] >= dp[1][i])
                dp[1][i] = dp[1][j] + 1;

        result = dp[0][i] + dp[1][i] - 1;
        if (result > ans)
            ans = result;
    }

    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //         cout << dp[i][j] << ' ';
    //     cout << '\n';
    // }

    // Output
    cout << ans << '\n';
    return 0;
}