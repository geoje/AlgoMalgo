// #include <cstdio> // For Test
#include <iostream>
using namespace std;

int n, m, s = 0, memory[100], cost[100], dp[100][10001] = {0};

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> memory[i];
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
        s += cost[i];
    }

    /* Process */
    dp[0][cost[0]] = memory[0];
    for (int i = 1; i < n; i++)
        for (int j = 0; j <= s; j++)
            if (j < cost[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + memory[i]);

    /* Output */
    for (int j = 0; j <= s; j++)
        if (dp[n - 1][j] >= m)
        {
            cout << j << '\n';
            break;
        }
    return 0;
}