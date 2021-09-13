#include <cstdio> // For Test
#include <iostream>
using namespace std;

const int INF = 2500;

string str;
bool isPd[2500][2500] = {0};
int dp[2500] = {0};

int palindrome(int a, int b)
{
    return 0;
}

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> str;
    int n = str.size();

    /* Process */
    // 팰린드롬인지 배열 만들기
    isPd[0][0] = true;
    for (int i = 1; i < n; i++)
        isPd[i][i - 1] = isPd[i][i] = true;

    for (int k = 1; k < n; k++)
        for (int i = k - 1, j = k; i >= 0 && j < n; i--, j++)
            isPd[i][j] = isPd[i + 1][j - 1] && str[i] == str[j];
    for (int k = 1; k < n; k++)
        for (int i = k - 1, j = k + 1; i >= 0 && j < n; i--, j++)
            isPd[i][j] = isPd[i + 1][j - 1] && str[i] == str[j];

    // 팰린드롬 체크
    dp[0] = 1;
    for (int i = 1; i < n; i++)
        if (isPd[0][i])
            dp[i] = 1;
        else
        {
            dp[i] = dp[i - 1] + 1;
            for (int j = 1; j < i; j++)
                if (isPd[j][i] && dp[j - 1] + 1 < dp[i])
                    dp[i] = dp[j - 1] + 1;
        }

    /* Output */
    cout << dp[n - 1] << '\n';
    return 0;
}