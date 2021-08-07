// #include <cstdio> // For Test
#include <iostream>
using namespace std;

int t, n, arr[2][100000];
int dp[2][100000];

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen(argv[1], "r", stdin); // For Test

    cin >> t;
    while (t-- > 0)
    {
        // Input
        cin >> n;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        // Process
        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        dp[0][1] = arr[1][0] + arr[0][1];
        dp[1][1] = arr[0][0] + arr[1][1];

        for (int j = 2; j < n; j++)
            for (int i = 0; i < 2; i++)
                dp[i][j] = max(dp[!i][j - 2], dp[!i][j - 1]) + arr[i][j];

        // Output
        cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
    }
    return 0;
}