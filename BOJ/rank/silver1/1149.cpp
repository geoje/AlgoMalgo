#include <iostream>
using namespace std;

const int INF = 2100000000;
int n, color[1000][3], dp[1000][3] = {0};

void Paint()
{
    // Boundary Condition
    for (int j = 0; j < 3; j++)
        dp[0][j] = color[0][j];

    // Recursive Property
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + color[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + color[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + color[i][2];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Input
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> color[i][j];

    // Process
    Paint();

    // Output
    n--;
    cout << min(min(dp[n][0], dp[n][1]), dp[n][2]) << '\n';
    return 0;
}