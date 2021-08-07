#include <iostream>
using namespace std;

int dp[5001] = {0};
const int INF = 2100000000;

int delivery(int n)
{
    if (dp[n])
        return dp[n];
    else if (n > 5)
        return dp[n] = min(delivery(n - 3) + 1, delivery(n - 5) + 1);
    else
        return INF;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Input
    int n;
    cin >> n;
    dp[3] = 1;
    dp[5] = 1;

    // Process & Output
    int ans = delivery(n);
    cout << (ans >= INF ? -1 : ans) << '\n';
    return 0;
}