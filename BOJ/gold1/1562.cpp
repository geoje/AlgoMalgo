#include <cstdio> // For Test
#include <iostream>
using namespace std;

// dp[length][last]
long n, dp[101][10] = {0};

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n;

    /* Process */
    dp[10][0] = 1;
    dp[10][9] = 1;

    /* Output */
    cout << n << '\n';
    return 0;
}