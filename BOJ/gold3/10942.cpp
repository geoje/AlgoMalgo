// #include <cstdio> // For Test
#include <iostream>
using namespace std;

int n, m, num[2001], dp[2001][2001];

int palindrome(int a, int b)
{
    if (dp[a][b] != -1)
        return dp[a][b];

    return dp[a][b] = palindrome(a + 1, b - 1) && num[a] == num[b];
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n;
    fill_n(&dp[0][0], 2001 * 2001, -1);
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        dp[i][i] = dp[i][i - 1] = 1;
    }
    cin >> m;

    int a, b;
    while (m--)
    {
        /* Input */
        cin >> a >> b;

        /* Process & Output */
        cout << palindrome(a, b) << '\n';
    }
    return 0;
}