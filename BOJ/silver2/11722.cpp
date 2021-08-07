// #include <cstdio>
#include <iostream>
using namespace std;

int n, ans = 0, a[1000], dp[1000];

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Input
    // freopen(argv[1], "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Process
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (a[j] < a[i] && dp[j] >= dp[i])
                dp[i] = dp[j] + 1;

        if (dp[i] > ans)
            ans = dp[i];
    }

    // Output
    cout << ans << '\n';
    return 0;
}