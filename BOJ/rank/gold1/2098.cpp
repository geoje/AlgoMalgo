// #include <cstdio> // For Test
#include <iostream>
using namespace std;

const int INF = 2e7;
int n, w[16][16], dp[16][65536] = {0};

int tsp(int start, int visit)
{
    if (dp[start][visit] != -1)
        return dp[start][visit];

    int result = INF;
    for (int next = 1; next < n; next++)
        if (visit & (1 << next))
            result = min(result, w[start][next] + tsp(next, visit & ~(1 << next)));

    return dp[start][visit] = result;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n;
    fill_n(&dp[0][0], 16 * 65536, -1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> w[i][j];
            if (i != j && w[i][j] == 0)
                w[i][j] = INF;
        }

    /* Process */
    // Boundary Condition
    for (int i = 0; i < n; i++)
        dp[i][0] = w[i][0];

    /* Output */
    cout << tsp(0, (1 << n) - 2) << '\n';

    // Debug Code
    // cout << '\n';
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < (1 << n); j++)
    //         cout << dp[i][j] << '\t';
    //     cout << '\n';
    // }

    return 0;
}